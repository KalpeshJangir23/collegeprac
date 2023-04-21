#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork(); // create a child process

    if (pid < 0) { // error occurred
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) { // child process
        printf("Child process - PID: %d, Parent PID: %d\n", getpid(), getppid());
    } else { // parent process
        printf("Parent process - PID: %d, Child PID: %d\n", getpid(), pid);
        int status;
        waitpid(pid, &status, 0); // wait for child to terminate
        if (WIFEXITED(status)) {
            printf("Child process has terminated with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process has terminated abnormally\n");
        }
    }

    return 0;
}
