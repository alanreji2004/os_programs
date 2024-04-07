
first.c
  
#include <stdio.h>

void main() {
    printf("this is the first.c called by execv\n");
    printf("process id of first program is %d",getpid());
}

second.c

#include <stdio.h>
#include <unistd.h>

void main() {
    char* args[] = {"./first.o", NULL};
    printf("before execv\n");
    printf("process id of second program is %d",getpid());
    execv(args[0], args);
    printf("after execv\n");
}
