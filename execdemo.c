#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char *args[] = {"ls", "-l", NULL};

    printf("Before execvp()\n");
    printf("About to replace this process\n");

    execvp(args[0], args);

    perror("execvp failed");

    return 1;
}
