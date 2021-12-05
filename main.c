#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t new_pid;
    new_pid = fork();
    if (new_pid < 0) {
        fprintf(stderr, "fork error \n");
        return 0;
    }
    else if (new_pid == 0) {
        fprintf(stdout, "\n This is child process\n");
        fprintf(stdout, "PID: %d\nParent pid: %d\n", getpid(), getppid());
        // fprintf(stdout, )
        return 0;
    }
    else {
        wait(NULL);
        fprintf(stdout, "\n This is parent process\n");
        fprintf(stdout, "PID: %d\nChild pid: %d\n", getpid(), new_pid);
    }
}
