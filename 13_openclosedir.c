#include<stdio.h>
#include<stdlib.h>
#include<sys/dir.h>
#include<string.h>

int search(char [], char []);

void main() {
    printf("Enter the name of the directory to search in: ");
    char name[60];
    scanf("%s", name);
    printf("Enter the name of the file to search: ");
    char f_name[60];
    scanf("%s", f_name);
    int a = search(name, f_name);
    if(a) {
        printf("File is not found\n");
    } else {
        printf("File is found\n");
    }
}

int search(char dname[], char file[]) {
    DIR *dptr = opendir(dname);
    if(dptr == NULL) {
        printf("Directory not found\n");
        exit(0);
    } else {
        struct dirent *entry = readdir(dptr);
        while(entry != NULL) {
            if(strcmp(entry->d_name, file) == 0)
                return 0;
            entry = readdir(dptr);
        }
        return 1;
    }
}
