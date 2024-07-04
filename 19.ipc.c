sender.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void main() {
    int shmid;
    char *s;
    key_t k;

    k = ftok('a', 5);
    shmid = shmget(k, 1024, IPC_CREAT | 0666);
    s = shmat(shmid, NULL, 0);

    printf("Enter a message: ");
    gets(s);

    while (*s != '*') {
        sleep(2);
    }

    shmdt(s);
    shmctl(shmid, IPC_RMID, 0);
}

receiver.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void main() {
    int shmid;
    char *s;
    key_t k;

    k = ftok('a', 5);
    shmid = shmget(k, 1024, IPC_CREAT | 0666);
    s = shmat(shmid, NULL, 0);

    printf("%s", s);
    *s = '*';

    shmdt(s);
    shmctl(shmid, IPC_RMID, 0);
}
