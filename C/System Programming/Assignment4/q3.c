#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/wait.h>

int pid; // Holds the pid of first fork

void action(int sig){} // Handles signals sent between parent and child

// Kills child process then ends program
void end_program(int sig)
{
	kill(pid, SIGINT);
	exit(0);
}

int main(int argc, char* argv[])
{
	// Delete the two FIFOs if the already exist
	unlink("../fifo1");
	unlink("../fifo2");

	// Make 2 FIFOs
	if(mkfifo("../fifo1", 0777) != 0 || mkfifo("../fifo2", 0777) != 0)
	{
		perror("FIFO could not be created");
		exit(1);
	}

	pid = fork();

	// Fork failure
	if(pid < 0)
	{
		perror("Fork failure");
		exit(1);
	}

	// Parent process
	else if(pid > 0)
	{
		signal(SIGUSR1, action); // Handles signals from the child process
		signal(SIGINT, end_program); // Handles ctrl-c to end program

		int fd1 = open("../fifo1", O_WRONLY); // Open FIFO1 for writing
		int fd2 = open("../fifo2", O_RDONLY); // Open FIFO2 for reading
		char buf[1024]; // Holds user input
		int pid2; // Holds pid of forked processes

		while(1)
		{
			printf("Please enter no more than 1024 characters:\n");
			fgets(buf, 1024, stdin);

			write(fd1, buf, sizeof(buf)); // Write buf to the first FIFO
			
			// Send signal to child so that it can change all the characters to uppercase and wait until it is done
			kill(pid, SIGUSR1);
			pause();

			read(fd2, buf, sizeof(buf)); // Read the uppercase buf from FIFO2

			// Fork failure
			if((pid2 = fork()) < 0)
			{
				perror("Fork failure");
				exit(1);
			}

			// Have the child process execute echo command with the new uppercase buf
			else if(pid2 == 0)
			{
				execlp("echo", "echo", buf, (char*) 0);
			}

			wait(NULL); // Wait for the child process to execute
		}
	}

	else
	{
		signal(SIGUSR1, action); // Handles signals from parent process

		int fd1 = open("../fifo1", O_RDONLY); // Open FIFO1 for reading
		int fd2 = open("../fifo2", O_WRONLY); // Open FIFO2 for writing
		char buf[1024]; // Holds user input and result of modifying the input
		
		while(1)
		{
			pause(); // Wait for the parent to get user input and send it through FIFO1

			// Read 1 character at a time form FIFO1 and convert every letter to upper-case
			for(int i = 0; (i < 1024) && (read(fd1, &buf[i], 1)) == 1; i++)
			{
				if(isalpha(buf[i]))
					buf[i] = toupper(buf[i]);
			}

			write(fd2, buf, sizeof(buf)); // Write the modified buf to FIFO2

			kill(getppid(), SIGUSR1); // Send signal to parent so that it may display the modified buf
		}
	}
}