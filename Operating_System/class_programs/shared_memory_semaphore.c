#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>

int main()
{
    // 1. Create or open the shared memory object
    int fd = shm_open("/counter", O_CREAT | O_RDWR, 0666);

    if (fd == -1)
    {
        perror("shm_open");
        return 1;
    }

    ftruncate(fd, sizeof(int));

    // Map memory with READ and WRITE permissions
    int *val = mmap(NULL, sizeof(int),
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED, fd, 0);

    if (val == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }

    *val = 100;

    // 2. Create or open the named semaphore
    // Initial value = 1 (mutex mode)
    sem_t *sem = sem_open("/counter_lock", O_CREAT, 0666, 1);

    if (sem == SEM_FAILED)
    {
        perror("sem_open");
        munmap(val, sizeof(int));
        close(fd);
        return 1;
    }

    // 3. Critical Section
    sem_wait(sem);

    *val = *val + 1;

    printf("Counter incremented to: %d\n", *val);

    sem_post(sem);

    // 4. Cleanup resources
    sem_close(sem);
    sem_unlink("/counter_lock");

    munmap(val, sizeof(int));
    close(fd);

    return 0;
}
