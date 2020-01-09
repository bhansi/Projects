/* The program asks for UNIX commands to be typed and inputted to a string*/
/* The string is then "parsed" by locating blanks etc. */
/* Each command and corresponding arguments are put in a args array */
/* execvp is called to execute these commands in child process */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int parse(char *buf, char *args[][3]);
void execute(char *args[][3], int size);

int main(int argc, char *argv[])
{
    char buf[1024];
    char *args[64][3]; // Holds the list of command and argument pairs

    for (;;)
    {
        // Prompt for and read a command.
        printf("\nCommand > ");
        if (fgets(buf, 1024, stdin) == NULL)
        {
            printf("\n");
            exit(0);
        }

        puts(""); // New-line for better readability

        // Split the string into arguments and execute them
        execute(args, parse(buf, args));
    }
}

/*
 * parse--split the command in buf into
 *         individual arguments.
 */
int parse(char *buf, char *args[][3])
{
    int count = 0; // Holds the number of command and argument pairs

    for(int i = 0; *buf != '\n'; i++)
    {
        /*
         * Strip whitespace.  Use nulls, so
         * that the previous argument is terminated
         * automatically.
         */
        while((*buf == ' ') || (*buf == '\t'))
            *buf++ = '\0';
            
        // Save the command
        if(i % 2 == 0)
        {
            args[count][0] = buf;
        }

        // Save the argument and NULL
        else
        {
            args[count][1] = buf;
            args[count][2] = NULL;
            count++;
        } 

        // Skip over the argument/new-line.
        while((*buf != '\0') && (*buf != ' ') && (*buf != '\t') && (*buf != '\n'))
            buf++;

        // Handles case where final command has no argument
        if((*buf == '\n') && (i % 2 == 0))
        {
            args[count][1] = NULL;
            args[count][2] = NULL;
            count++;
        }
    }

    *buf = '\0'; // Changes the '\n' to '\0'
    return count;
}

/*
 * execute--spawn child processes and execute
 *           them.
 */
void execute(char *args[][3], int size)
{
    int pid;

	for(int i = 0; i < size; i++)
	{
        // Child process
  	    if((pid = fork()) == 0)
		{ 
			printf("[son] pid %d from [parent] pid %d\n", getpid(), getppid()); 
			execvp(args[i][0], args[i]); // Execute command i
	  	}
		
        // Fork error
		else if(pid < 0)
		{
			perror("Fork Error");
			exit(1);
		}
	}

    // Parent waits for each child to finish executing
	for(int i = 0; i < size; i++)
		wait(NULL);
}