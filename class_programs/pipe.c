#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd[2];

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        // Child: reader
        close(fd[1]);

        char buf[128];
        ssize_t n;

        while ((n = read(fd[0], buf, sizeof(buf))) > 0)
        {
            write(STDOUT_FILENO, buf, n);
        }

        close(fd[0]);
    }
    else
    {
        // Parent: writer
        close(fd[0]);

        write(fd[1], "Hello, child!\n", 14);

        close(fd[1]);   // triggers EOF

        wait(NULL);
    }

    return 0;
}
