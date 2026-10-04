#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    const char *message = "Hello World\n";
    size_t message_len = strlen(message);

    ssize_t bytes_written = write(fd, message, message_len);

    if (bytes_written == -1)
    {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Successfully wrote all %ld bytes to the file!\n", bytes_written);

    close(fd);

    return 0;
}
