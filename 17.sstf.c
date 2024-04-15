#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main() {
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size;

    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    
    printf("Enter the Requests sequence\n");
    for(i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position\n");
    scanf("%d", &initial);

    printf("Enter total disk size\n");
    scanf("%d", &size);

    int visited[100] = {0};

    int minDistance, closestIndex;
    while(1) {
        minDistance = INT_MAX;
        closestIndex = -1;
        for(i = 0; i < n; i++) {
            if(abs(RQ[i] - initial) < minDistance && !visited[i]) {
                minDistance = abs(RQ[i] - initial);
                closestIndex = i;
            }
        }

        if(closestIndex == -1)
            break;

        TotalHeadMoment += minDistance;
        visited[closestIndex] = 1;
        initial = RQ[closestIndex];
    }

    printf("Total head movement is %d\n", TotalHeadMoment);

    return 0;
}
