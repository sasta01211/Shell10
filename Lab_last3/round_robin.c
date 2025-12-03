#include <stdio.h>

/*
 Round Robin (assumes arrival time = 0 for all)
 Compile: gcc -o rr round_robin.c
*/
int main() {
    int n, bt[100], rem[100], wt[100], tat[100], tq;
    int i, time = 0, done;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Burst time of P%d: ", i+1);
        scanf("%d",&bt[i]);
        rem[i] = bt[i];
        wt[i] = 0;
    }
    printf("Enter time quantum: ");
    scanf("%d",&tq);
    if(tq <= 0){
        printf("Time quantum must be positive.\n");
        return 0;
    }
    do {
        done = 1;
        for(i=0;i<n;i++){
            if(rem[i] > 0){
                done = 0;
                int exec = (rem[i] > tq) ? tq : rem[i];
                time += exec;
                rem[i] -= exec;
                for(int j=0;j<n;j++)
                    if(j!=i && rem[j] > 0) wt[j] += exec;
            }
        }
    } while(!done);
    for(i=0;i<n;i++) tat[i]=wt[i]+bt[i];
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++) printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    return 0;
}
