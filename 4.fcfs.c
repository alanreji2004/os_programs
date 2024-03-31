#include <stdio.h>
struct process{
    int processnumber;
    int bursttime;
    int arrivaltime;
    int waitingtime;
    int turnaroundtime;
};

void main(){
    int n,i,j;
    int currenttime = 0;
    float total_waitingtime = 0,total_turnaroundtime = 0;
    printf("\nEnter the number of the processes : ");
    scanf("%d",&n);
    struct process p[n];
    printf("\nEnter the arrival time and the burst time of each processes\n");
    for(i=0;i<n;i++){
        p[i].processnumber = i + 1;
        printf("Enter the arrival time and burst time of P%d : ",i + 1);
        scanf("%d%d",&p[i].arrivaltime,&p[i].bursttime);
    }
    struct process temp;
    for(i=0;i<n;i++){
        for(j=0;j<n-1-i;j++){
            if(p[j].arrivaltime > p[j + 1].arrivaltime){
                temp = p[j];
                p[j] = p[j+1];
                p[j + 1] = temp;
            }
        }
    }
    printf("\nGiven Processes\n");
    printf("Process number\t\tArrival time\t\tBursttime");
    for(i=0;i<n;i++){
        printf("\nP%d\t\t\t\t%d\t\t\t\t%d",p[i].processnumber,p[i].arrivaltime,p[i].bursttime);
    }
    for(i=0;i<n;i++){
        if(currenttime <= p[i].arrivaltime){
                currenttime = p[i].arrivaltime;
        }
            p[i].waitingtime = currenttime - p[i].arrivaltime;
            total_waitingtime += p[i].waitingtime;
            currenttime = currenttime + p[i].bursttime;
            p[i].turnaroundtime = currenttime - p[i].arrivaltime;
            total_turnaroundtime += p[i].turnaroundtime;
    }
    printf("\n****OUTPUT***\n");
    printf("process number\t\tWaiting time\t\tTurn around time");
    for(i=0;i<n;i++){
        printf("\nP%d\t\t\t\t%d\t\t\t\t%d",p[i].processnumber,p[i].waitingtime,p[i].turnaroundtime);
    }
    printf("\nAverage Waiting time : %f",(double)total_waitingtime/n);
    printf("\nAverage Turn around time : %f",(double)total_turnaroundtime/n);

}









