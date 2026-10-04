#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    printf("=== STAGE 1: Before fork() (Single Process) ===\n");
    printf("[Initial] PID: %d, PPID: %d | State: Running\n\n", getpid(), getppid());

    printf("=== STAGE 2: Executing fork() ===\n");
    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        printf("[Child]   STAGE 3: Child Process Created\n");
        printf("[Child]   PID: %d, PPID: %d | State: Active/Running\n", getpid(), getppid());

        printf("[Child]   Going to sleep for 2 seconds to simulate work...\n");
        sleep(2);

        printf("[Child]   STAGE 4: Child Finishing\n");
        printf("[Child]   PID: %d | State: About to Terminate\n", getpid());

        exit(0);
    }
    else
    {
        printf("[Parent]  STAGE 3: Parent Continues\n");
        printf("[Parent]  PID: %d, PPID: %d, Created Child PID: %d | State: Active/Running\n", getpid(), getppid(), pid);

        printf("[Parent]  Waiting for child process to finish...\n");

        int status;
        wait(&status);

        printf("\n=== STAGE 5: After wait() (Child Reaped) ===\n");
        printf("[Parent]  Child has been successfully reaped.\n");
        printf("[Parent]  PID: %d | State: Finishing Execution\n", getpid());
    }

    return 0;
}
