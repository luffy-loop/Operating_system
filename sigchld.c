#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// Signal handler for SIGCHLD
void clean_child(int sig)
{
    // Collect the terminated child so it does not become a zombie
    wait(NULL);

    printf("\n[Signal] A child process was successfully cleaned up.\n");
}

int main()
{
    // Tell the OS to call clean_child when the child terminates
    signal(SIGCHLD, clean_child);

    // Create a child process
    if (fork() == 0)
    {
        // Child process
        printf("Child process running... sleeping for 2 seconds.\n");

        sleep(2);

        printf("Child process exiting now.\n");

        exit(0);
    }

    // Parent process
    while (1)
    {
        printf("Parent doing its own work...\n");
        sleep(1);
    }

    return 0;
}
