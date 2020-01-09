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

void parse(char *buf, char **args);
void execute(char **args);
char *gets(char *s);

int main(int argc, char *argv[])
{
    char buf[1024];
    char *args[64];

    for (;;)
    {
        /*
         * Prompt for and read a command.
         */
        printf("Command: ");
        if (fgets(buf, 1024, stdin) == NULL)
        {
            printf("\n");
            exit(0);
        }

        /*
         * Split the string into arguments.
         */
        parse(buf, args);

        /*
         * Execute the command.
         */
        execute(args);
    }
}

/*
 * parse--split the command in buf into
 *         individual arguments.
 */
void parse(char *buf, char **args)
{
    while (*buf != '\0') {
        /*
         * Strip whitespace.  Use nulls, so
         * that the previous argument is terminated
         * automatically.
         */
        while ((*buf == ' ') || (*buf == '\t'))
            *buf++ = '\0';

        /*
         * Save the argument.
         */
        *args++ = buf;

        /*
         * Skip over the argument.
         */
        while ((*buf != '\0') && (*buf != ' ') && (*buf != '\t'))
            buf++;
    }

    *(buf - 1) = '\0'; // Change the '\n' at the end of the command to '\0'
    *args = NULL;
}

/*
 * execute--spawn a child process and execute
 *           the program.
 */
void execute(char **args)
{
    int pid = fork();

    if(pid < 0)
    {
        perror("Fork Error");
        exit(1);
    }

    else if(pid > 0) // Parent waits for child to execute
        wait(NULL);

    else // Child executes command in args
        execvp(args[0], args);
}