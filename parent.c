// First child : slept for 1 second.
//Second child : slept for 3 seconds.
// Parent : Both children have finished.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2;

    child1 = fork();
    if (child1 == 0) {
        // First child process
        sleep(1);
        printf("First child : slept for 1 second.\n");
        exit(0);
    }

    child2 = fork();
    if (child2 == 0) {
        // Second child process
        sleep(3);
        printf("Second child : slept for 3 seconds.\n");
        exit(0);
    }

    // Parent process waits for both children to finish
    wait(NULL);
    wait(NULL);
    printf("Parent : Both children have finished.\n");

    return 0;
}
