#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

// Signal handler for SIGALRM
void alarmHandler(int sig)
{
    printf("Ding!\n");
}

int main(int argc, char* argv[])
{
    int pid;
    int time = atoi(argv[1]); // Holds the argument value for how many seconds to wait before alarm dings

    // Fork error
    if((pid = fork()) < 0)
    {
        perror("Fork Error");
            exit(1);
    }

    // Child process
    else if(pid == 0)
    {
        printf("Alarm application starting.\nWaiting for alarm to go off.\n<%d second pause>\n", time);
        sleep(time);
        kill(getppid(), SIGALRM); // Send alarm signal to parent
    }

    else // Parent Process
    {
        signal(SIGALRM, alarmHandler); // Change signal handler for SIGALRM to alarmHandler()
        pause(); // Wait for child process to send signal
        puts("Done.");
    }

    return 0;
}