#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("data.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    struct stat sb;

    if (fstat(fd, &sb) == -1)
    {
        perror("Error getting file size");
        close(fd);
        return 1;
    }

    size_t filesize = sb.st_size;

    if (filesize == 0)
    {
        printf("File is empty\n");
        close(fd);
        return 0;
    }

    char *data = mmap(NULL, filesize, PROT_READ, MAP_SHARED, fd, 0);

    if (data == MAP_FAILED)
    {
        perror("mmap-error");
        close(fd);
        return 1;
    }

    printf("First 20 bytes: %.20s\n", data);
    fwrite(data, 1, filesize, stdout);

    munmap(data, filesize);
    close(fd);

    return 0;
}
