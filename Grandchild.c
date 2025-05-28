/* The parent creates a child process.
The child creates a grandchild process.
The grandchild sleeps 2 seconds and exits with status .
The child waits for the grand child, prints its exit status 
then exits with status 55. */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid, grandchild_pid;
    int status;

    child_pid = fork();
    if (child_pid == 0) {
        // Child process
        grandchild_pid = fork();
        if (grandchild_pid == 0) {
            // Grandchild process
            sleep(2);
            exit(42); // Grandchild exits with status 42
        }

        // Child waits for grandchild
        waitpid(grandchild_pid, &status, 0);
        printf("Child: Grandchild exited with status %d.\n", WEXITSTATUS(status));

        exit(55); // Child exits with status 55
    }

    // Parent waits for child
    waitpid(child_pid, &status, 0);
    printf("Parent: Child exited with status %d.\n", WEXITSTATUS(status));

    return 0;
}
