#include <stdio.h>
#include <sys/stat.h>

void main() {
    printf("Enter the name of the file: ");
    char f_name[78];
    scanf("%s", f_name);
    struct stat s;
    stat(f_name, &s);
    printf("Last access time of file: %ld\n", s.st_atime);
    printf("Last modified time: %d\n", s.st_mtime);
    printf("Size of file: %d\n", s.st_size);
    printf("File mode: %o\n", s.st_mode);
}
