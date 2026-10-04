#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int src_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    // Check if the user provided the correct number of arguments
    if (argc != 3) {
        printf("in sufficient arguments\n");
        exit(1);
    }

    // 1. Open the source file for reading only
    src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("Error opening source file");
        exit(1);
    }

    // 2. Open/Create the destination file for writing only
    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening/creating destination file");
        close(src_fd); // Clean up opened source file descriptor
        exit(1);
    }

    // 3. Read from source and write to destination using a buffer
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            exit(1);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading source file");
    }

    // 4. Close both file descriptors
    close(src_fd);
    close(dest_fd);

    printf("File copied successfully ");
    return 0;
}
