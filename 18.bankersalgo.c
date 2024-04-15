#include<stdio.h>

void main() {
    int no_of_process, no_of_resource = 3, available[10], work[10], 
        max[10][10], need[10][10], allocation[10][10];
    int i, j, flag = 0, ss[10], k = 0, finish[10], l;

    printf("Enter number of processes and resources:");
    scanf("%d%d", &no_of_process, &no_of_resource);

    printf("Enter allocation matrix\n");
    for(i = 0; i < no_of_process; i++)
        for(j = 0; j < no_of_resource; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter max matrix\n");
    for(i = 0; i < no_of_process; i++)
        for(j = 0; j < no_of_resource; j++)
            scanf("%d", &max[i][j]);

    printf("Enter available resources\n");
    for(i = 0; i < no_of_resource; i++) {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }

    for(i = 0; i < no_of_process; i++)
        finish[i] = 0;

    for(i = 0; i < no_of_process; i++)
        for(j = 0; j < no_of_resource; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    printf("Need Matrix is\n");
    for(i = 0; i < no_of_process; i++) {
        for(j = 0; j < no_of_resource; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    for(l = 0; l < no_of_process; l++) {
        for(i = 0; i < no_of_process; i++) {
            flag = 0;
            if(finish[i] == 0) {
                for(j = 0; j < no_of_resource; j++) {
                    if(need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    for(j = 0; j < no_of_resource; j++) {
                        work[j] += allocation[i][j];
                    }
                    ss[k] = i;
                    k = k + 1;
                    finish[i] = 1;
                }
            }
        }
    }

    flag = 1;
    for(i = 0; i < no_of_process; i++) {
        if(finish[i] == 0) {
            flag = 0;
            printf("System is not safe\n");
            break;
        }
    }
    if(flag == 1) {
        printf("Safe Sequence is:") ;
        for(i = 0; i < no_of_process - 1; i++)
            printf("P%d->", ss[i]);
        printf("P%d", ss[no_of_process - 1]);
    }
}


/*
  output
Enter number of processes and resources:5
3
Enter allocation matrix
0
1
0
2
0
0
3
0
2
2
1
1
0
0
2
Enter max matrix
7
5
3
3
2
2
9
0
2
2
2
2
4
3
3
Enter available resources
3
3
2
Need Matrix is
7 4 3 
1 2 2 
6 0 0 
0 1 1 
4 3 1 
Safe Sequence is:P1->P3->P4->P0->P
  */
