#include <stdio.h>
#include <unistd.h>

int main()
{
    char *args[] = {"./Hello", NULL};

    printf("About to replace this image\n");

    execvp(args[0], args);

    // Only reached if execvp() fails
    perror("execvp failed");

    return 1;
}
