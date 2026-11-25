#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
    int fd = shm_open("/counter", O_RDONLY, 0666);

    if (fd == -1)
    {
        perror("shm_open");
        return 1;
    }

    int *val = mmap(NULL, sizeof(int),
                    PROT_READ,
                    MAP_SHARED,
                    fd, 0);

    if (val == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }

    printf("Value read from shared memory: %d\n", *val);

    munmap(val, sizeof(int));
    close(fd);

    return 0;
}
