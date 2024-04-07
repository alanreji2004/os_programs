#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("pid of child: %d\npid of parent of child: %d\n", getpid(), getppid());
    }
    if (pid > 0) {
        wait(NULL);
        printf("pid of parent: %d\npid of parent of parent: %d\n", getpid(), getppid());
    }
}
