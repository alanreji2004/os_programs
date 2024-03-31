#include<stdio.h>

struct process {
    int size;
    int allocated;
};

void main() {
    int nb, np, best;
    printf("Enter the number of memory locations: ");
    scanf("%d", &nb);
    int block[nb];
    printf("Enter the size of memory locations: ");
    for (int i = 0; i < nb; i++) {
        scanf("%d", &block[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    struct process pro[np];
    printf("Enter the size of each process: ");
    for (int i = 0; i < np; i++) {
        scanf("%d", &pro[i].size);
        pro[i].allocated = -1;
    }
    for (int i = 0; i < np; i++) {
        best = -1;
        for (int j = 0; j < nb; j++) {
            if (pro[i].size <= block[j]) {
                if (best == -1) {
                    best = j;
                } else if (block[j] < block[best]) {
                    best = j;
                }
            }
        }
        if (best != -1) {
            pro[i].allocated = block[best];
            block[best] = block[best] - pro[i].size;
        }
    }
    printf("\nSI.No\tProcess\tAllocated");
    for (int i = 0; i < np; i++) {
        if (pro[i].allocated != -1) {
            printf("\n%d\t%d\t%d", i + 1, pro[i].size, pro[i].allocated);
        } else {
            printf("\n%d\t%d\tNot allocated", i + 1, pro[i].size);
        }
    }
    printf("\n");
}
