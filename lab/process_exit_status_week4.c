#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child running: ");
        printf("hi\n");

        exit(17);
    }
    else
    {
        int status;

        pid_t child_pid = wait(&status);

        printf("Child %d exited with %d\n",
               child_pid, WEXITSTATUS(status));

        return 0;
    }
}
