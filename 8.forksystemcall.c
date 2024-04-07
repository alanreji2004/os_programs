#include<stdio.h>
#include<unistd.h>
void main(){
  fork();
  printf("hello\n");
  fork();
  printf("world\n");
}
