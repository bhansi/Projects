#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{  
	int fd;
	char ch;
	char message[25];
	
	// Open the FIFO for reading and writing
	while((fd = open("../myserver", O_RDWR)) == -1)
	{  
		fprintf(stderr, "trying to connect\n");
		sleep(1);
	}

	printf("Connected: type in data to be sent\n");

	while((ch = getchar()) != -1) // -1 is CTRL-D
	{
		write(fd, &ch, 1);

		// Once the data is sent to the server, read the message server
		if(ch == '\n')
		{
			sleep(1);
			read(fd, message, 25);
			fprintf(stderr, "Server says: %s", message);
		}
	}
	
	close(fd);
}

