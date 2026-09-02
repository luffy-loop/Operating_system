#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
    // Create or open shared memory object
    int fd = shm_open("/counter", O_CREAT | O_RDWR, 0666);

    if (fd == -1)
    {
        perror("shm_open");
        return 1;
    }

    // Allocate size for shared memory
    ftruncate(fd, sizeof(int));

    // Map shared memory into process address space
    int *val = mmap(NULL, sizeof(int),
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED, fd, 0);

    if (val == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }

    // Write value into shared memory
    *val = 42;

    printf("Value written to shared memory: %d\n", *val);

    // Unmap shared memory
    munmap(val, sizeof(int));

    // Close file descriptor
    close(fd);

    return 0;
}
