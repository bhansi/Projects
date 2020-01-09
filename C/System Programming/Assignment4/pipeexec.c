#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int fd[2], pid;

    // Creating pipe
    if(pipe(fd) == -1)
    {
        perror("Pipe Failure");
        exit(1);
    }

    // Fork failure
    if((pid = fork()) < 0)
    {
        perror("Fork Failure.");
        exit(1);
    }

    // Parent
    else if(pid > 0)
    { 
        wait(NULL); // Wait for child to execute the command

        FILE* file;
        char ch;
        int count = 0;

        close(fd[1]); // Close the writing end of the pipe

        // Open the output file for writing
        if((file = fopen("result.txt", "w")) == NULL)
        {
            perror("Failed to open \"result.txt\"");
            exit(1);
        }

        for(int i = 0; read(fd[0], &ch, 1) == 1; i++)
        {
            // Don't print the command name to the output file
            if(i < sizeof(argv[1]) - 1)
                continue;
                   
            fprintf(file, "%c", ch); // Print the output of execlp to the output file
            count++;
        }

        printf("The result of %s is written into result.txt with total %d bytes.\n", argv[1], count);
        fclose(file);
    }

    // Child
    else
    {
        close(fd[0]); // Close the reading end of the pipe

        dup2(fd[1], 1); // Send stdout to the writing end of the pipe
        dup2(fd[1], 2); // Send stderr to the writing end of the pipe

        execlp(argv[1], argv[1], (char*) 0); // Execute the command
    }
    
}