#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
 
#define MAX_ARGS 20
#define MAX_LEN 100
 
int main() {
   char command[MAX_LEN];
   char *args[MAX_ARGS];
   int i = 0;
 
   printf("Enter a Linux command: ");
   if (fgets(command, sizeof(command), stdin) == NULL) {
       return 0;
   }
 
   // Remove newline character
   command[strcspn(command, "\n")] = '\0';
 
   // Split command into arguments
   args[i] = strtok(command, " ");
   while (args[i] != NULL && i < MAX_ARGS - 1) {
       i++;
       args[i] = strtok(NULL, " ");
   }
   args[i] = NULL; // Explicitly ensure the array is NULL-terminated

   // Guard against empty inputs (pressing enter without typing)
   if (args[0] == NULL) {
       printf("No command entered.\n");
       return 0;
   }
 
   pid_t pid = fork();
 
   if (pid < 0) {
       printf("Fork failed.\n");
       exit(1);
   }
   else if (pid == 0) {
       // Child Process
       printf("\n--- Child Process Running ---\n");
       printf("Child PID  : %d\n", getpid());
       printf("Parent PID : %d\n\n", getppid());
 
       execvp(args[0], args);
 
       // Executes only if exec fails
       perror("Execution failed");
       exit(1);
   }
   else {
       // Parent Process
       printf("\n--- Parent Process Waiting ---\n");
       printf("Parent PID : %d\n", getpid());
       printf("Child PID  : %d\n", pid);
 
       wait(NULL);
 
       printf("\nChild process has completed execution.\n");
   }
 
   return 0;
}
