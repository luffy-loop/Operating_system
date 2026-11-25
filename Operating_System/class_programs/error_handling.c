#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    int fd;

    fd = open("marks.txt", O_RDONLY);

    if (fd == -1)
    {
        printf("Error Number: %d\n", errno);
    }

    return 0;
}
