#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#define SIGSTP 20

// Signal handler for SIGINT (user presses ctrl-c)
void sigHandler(int sig)
{
    puts("ctrl-c was pressed!");
}

int main(int argc, char* argv[])
{
    // Change signal handler for SIGINT and ignore SIGSTP
    if((signal(SIGINT, sigHandler) == SIG_ERR) || (signal(SIGSTP, SIG_IGN) == SIG_ERR))
    {
        perror("signal");
		exit(4);
    }

    puts("ctrl-c and ctrl-z do not affect me now.");
    puts("ctrl-c will affect me in 10 seconds");

    // 10 seconds where both ctrl-c and ctrl-z will not stop the program
    for(int i = 0; i < 10; i++)
        sleep(1);
    
    puts("ctrl-c now affects me but I still ignore ctrl-z.");
    // Execute the donothing program
    execlp("./donothing", "./donothing", NULL);
}