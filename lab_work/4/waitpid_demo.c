#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t c0, c1, c2, reaped;
    int status;

    printf("[Parent] PID: %d\n\n", getpid());

    if ((c0 = fork()) == 0)
    {
        sleep(6);
        exit(100);
    }

    if ((c1 = fork()) == 0)
    {
        sleep(4);
        exit(101);
    }

    if ((c2 = fork()) == 0)
    {
        sleep(2);
        exit(102);
    }

    sleep(1);

    // Targeted waitpid() for Child 1
    printf("--- Targeted waitpid() ---\n");

    waitpid(c1, &status, 0);

    printf("Reaped Child 1 (PID: %d). Exit code: %d\n\n",
           c1, WEXITSTATUS(status));

    // Catch-all wait() for remaining children
    printf("--- Catch-all wait() ---\n");

    while ((reaped = wait(&status)) > 0)
    {
        printf("Reaped child (PID: %d). Exit code: %d\n",
               reaped, WEXITSTATUS(status));
    }

    printf("\n[Parent] All children reaped. Exiting.\n");

    return 0;
}

