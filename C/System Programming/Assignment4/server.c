#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

// This is the server
int main(int argc, char *argv[])
{  
	int fd;
	char ch;
	char message[] = "I recieved your message\n";

	unlink("../myserver"); // delete it if it exists

	if(mkfifo("../myserver", 0777) != 0)
	{
		puts("error");
		exit(1);
	}

	while(1)
	{
		fprintf(stderr, "Waiting for a client\n");

		fd = open("../myserver", O_RDWR); // Open the FIFO for reading and writing
		fprintf(stderr, "Got a client.\nNow printing messages from the client:\n");

		while(read(fd, &ch, 1) == 1)
		{
			fprintf(stderr, "%c", ch);

			// Once the data from the client is printed, send the "I have recieved your message" message to the client
			if(ch == '\n')
			{
				write(fd, message, sizeof(message)/sizeof(message[0]));
				sleep(1);
			}
		}
	}
}

