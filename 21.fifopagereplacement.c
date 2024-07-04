#include <stdio.h> 

void main() { 
    int i, j, n, rs[50], frame[10], nf, k, avail, pagefault = 0; 

    printf("\nEnter the number of pages:\n"); 
    scanf("%d", &n); 

    printf("\nEnter the reference string:\n"); 
    for(i = 0; i < n; i++) 
        scanf("%d", &rs[i]); 

    printf("\nEnter the number of frames: "); 
    scanf("%d", &nf); 

    for(i = 0; i < nf; i++) 
        frame[i] = -1; 

    j = 0; 
    printf("Ref string\tPage frames\n"); 
    for(i = 0; i < n; i++) { 
        printf("%d\t\t", rs[i]); 
        avail = 0; 
        for(k = 0; k < nf; k++) 
            if(frame[k] == rs[i]) 
                avail = 1; 

        if(avail == 0) { 
            frame[j] = rs[i]; 
            j = (j + 1) % nf; 
            pagefault++; 
            for(k = 0; k < nf; k++) 
                printf("%d\t", frame[k]); 
        } 
        printf("\n"); 
    } 
    printf("Page Fault Is: %d", pagefault); 
}
