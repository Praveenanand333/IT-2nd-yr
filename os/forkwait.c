#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;
    
    // Fork a child process
    pid = fork();
    
    if (pid == 0) {
        // Child process
        printf("Child process executing...\n");
        printf("Child process exiting with status code 42...\n");
        exit(42);
    } else if (pid > 0) {
        // Parent process
        printf("Parent process waiting for child to exit...\n");
        wait(&status);
        
        if (WIFEXITED(status)) {
            printf("Child exited with status code %d\n", WEXITSTATUS(status));
        } else {
            printf("Child did not exit normally\n");
        }
    } else {
        // Fork failed
        printf("Fork failed\n");
        exit(1);
    }
    
    printf("Exiting parent process...\n");
    exit(0);
}
/*We then define a main function, which first declares two variables: pid_t pid to store the process ID returned by the fork function, and int status to store the exit status of the child process.

We then call fork to create a child process. If fork returns 0, we are in the child process, so we print some output, set the exit status to 42 using exit, and exit the child process.

If fork returns a positive value, we are in the parent process, so we print some output indicating that we are waiting for the child process to exit. We then call wait to wait for the child process to exit, and store the exit status in the status variable.

We then use the WIFEXITED macro to check whether the child process exited normally, and print the exit status using WEXITSTATUS if it did. If the child process did not exit normally, we print a message indicating this.

Finally, we print a message indicating that we are exiting the parent process, and call exit to exit the program.

I hope this program helps you understand the exit system call and how it can be used in C programs. Let me know if you have any questions!*/
