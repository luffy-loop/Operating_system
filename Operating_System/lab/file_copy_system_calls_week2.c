#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int src_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    // Check if the user provided the correct number of arguments
    if (argc != 3)
    {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the source file for reading
    src_fd = open(argv[1], O_RDONLY);

    if (src_fd == -1)
    {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Open/Create the destination file
    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (dest_fd == -1)
    {
        perror("Error opening destination file");
        close(src_fd);
        exit(EXIT_FAILURE);
    }

    // Read from source and write to destination
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0)
    {
        bytes_written = write(dest_fd, buffer, bytes_read);

        if (bytes_written != bytes_read)
        {
            perror("Write Error");
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    // Check for read error
    if (bytes_read == -1)
    {
        perror("Read Error");
    }

    // Close both files
    close(src_fd);
    close(dest_fd);

    printf("File copied successfully.\n");

    return 0;
}

