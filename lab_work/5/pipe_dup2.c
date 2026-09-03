#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fd[2];

    pipe(fd);

    // Child 1: cat
    if (fork() == 0)
    {
        close(fd[0]);

        dup2(fd[1], STDOUT_FILENO);

        close(fd[1]);

        execlp("cat", "cat", "abc.txt", NULL);
    }

    // Child 2: wc
    if (fork() == 0)
    {
        close(fd[1]);

        dup2(fd[0], STDIN_FILENO);

        close(fd[0]);

        execlp("wc", "wc", "-l", NULL);
    }

    // Parent
    close(fd[0]);
    close(fd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}
