#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    // Stage 1: Before fork
    printf("STAGE 1: Before fork() (Single Process)\n");
    printf("[Initial] PID: %d, PPID: %d State: Running\n",
           getpid(), getppid());

    // Stage 2: Create child process
    printf("STAGE 2: Executing fork()\n");

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    else if (pid == 0)
    {
        // Child process

        printf("[Child] STAGE 3: Child Process Created\n");
        printf("[Child] PID: %d, PPID: %d State: Active\n",
               getpid(), getppid());

        // Simulating some work
        printf("[Child] Going to sleep for 2 seconds to simulate work...\n");
        sleep(2);

        printf("[Child] STAGE 4: Child finishing\n");
        printf("[Child] PID: %d State: About to terminate\n",
               getpid());

        exit(0);
    }

    else
    {
        // Parent process

        printf("[Parent] STAGE 3: Parent Continues\n");
        printf("[Parent] PID: %d, PPID: %d created child PID: %d State: Active\n",
               getpid(), getppid(), pid);

        printf("[Parent] Waiting for child process to finish...\n");

        // Parent waits for child
        int status;
        wait(&status);

        printf("STAGE 5: After wait() (Child Reaped)\n");
        printf("[Parent] Child has been successfully reaped.\n");
        printf("[Parent] PID: %d State: Finishing execution\n",
               getpid());
    }

    return 0;
}
