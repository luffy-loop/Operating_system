#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define FIFO_NAME "/tmp/my_fifo"

#ifdef PROCESS_A

int main()
{
    mkfifo(FIFO_NAME, 0666);

    printf("[Process A] Opening FIFO to write...\n");

    int fd = open(FIFO_NAME, O_WRONLY);

    char message[] = "Hello from Process A!";

    write(fd, message, strlen(message) + 1);

    printf("[Process A] Sent: %s\n", message);

    close(fd);

    return 0;
}

#endif

#ifdef PROCESS_B

int main()
{
    printf("[Process B] Opening FIFO to read...\n");

    int fd = open(FIFO_NAME, O_RDONLY);

    char buffer[100];

    read(fd, buffer, sizeof(buffer));

    printf("[Process B] Received: %s\n", buffer);

    close(fd);

    unlink(FIFO_NAME);

    return 0;
}

#endif
