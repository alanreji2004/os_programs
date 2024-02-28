#include<stdio.h>
 
struct process {
  
int size;
    int allocated;
};

void main() {
    int nb, np;
    
    printf("Enter the number of memory locations: ");
    scanf("%d", &nb);
    
    if (nb <= 0) {
        printf("Number of memory locations should be greater than zero.\n");
        return;
    }
    
    int block[nb];
    
    printf("Enter the size of memory locations: ");
    for(int i = 0; i < nb; i++) {
        scanf("%d", &block[i]);
    }
    
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    
    if (np <= 0) {
        printf("Number of processes should be greater than zero.\n");
        return;
    }
    
    struct process pro[np];
    
    printf("Enter the size of each process: ");
    for(int i = 0; i < np; i++) {
        scanf("%d", &pro[i].size);
        pro[i].allocated = -1;
    }
    
    for(int i = 0; i < np; i++) {
        for(int j = 0; j < nb; j++) {
            if (block[j] >= pro[i].size) {
                pro[i].allocated = block[j];
                block[j] -= pro[i].size;
                break;
            }
        }
    }
    
    printf("\nSI.No\tProcess\tAllocated");
    
    for(int i = 0; i < np; i++) {
        if(pro[i].allocated != -1) {
            printf("\n%d\t%d\t%d", i + 1, pro[i].size, pro[i].allocated);
        } else {
            printf("\n%d\t%d\tnot allocated", i + 1, pro[i].size);
        }
    }
    
    printf("\n");
}
