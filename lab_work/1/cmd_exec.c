#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 20
#define MAX_LEN 100

int main()
{
    char command[MAX_LEN];
    char *args[MAX_ARGS];
    int i = 0;

    printf("Enter any command:\n");

    if (fgets(command, sizeof(command), stdin) == NULL)
    {
        return 0;
    }

    // Remove newline character
    command[strcspn(command, "\n")] = '\0';

    // Split command into arguments
    args[i] = strtok(command, " ");

    while (args[i] != NULL && i < MAX_ARGS - 1)
    {
        i++;
        args[i] = strtok(NULL, " ");
    }

    args[i] = NULL;

    if (args[0] == NULL)
    {
        printf("No command entered.\n");
        return 0;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed!\n");
        exit(1);
    }
    else if (pid == 0)
    {
        // Child process
        printf("\nChild Process Running\n");
        printf("Child PID : %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        execvp(args[0], args);

        // Executes only if execvp fails
	perror("Command execution failed");
        exit(1);
    }
    else
    {
        // Parent process
        wait(NULL);
        printf("\nParent Process Resumed\n");
        printf("Parent PID: %d\n", getpid());
    }

    return 0;
}


