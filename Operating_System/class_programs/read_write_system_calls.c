#include <stdio.h>
#include <unistd.h>

int main()
{
    char buffer[256];

    ssize_t bytes_read = read(0, buffer, 256);

    if (bytes_read == -1)
    {
        perror("read error");
    }
    else if (bytes_read == 0)
    {
        printf("EOF reached\n");
    }
    else
    {
        printf("Read %ld bytes\n", bytes_read);
        write(1, buffer, bytes_read);
    }

    return 0;
}
