#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd[2];

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        close(fd[1]);

        char buf[100];

        read(fd[0], buf, sizeof(buf));

        printf("Child received: %s\n", buf);

        close(fd[0]);
    }
    else
    {
        // Parent process
        close(fd[0]);

        write(fd[1], "Hello from parent", 18);

        close(fd[1]);

        wait(NULL);
    }

    return 0;
}
