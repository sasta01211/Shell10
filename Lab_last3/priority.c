#include <stdio.h>

/*
 Non-preemptive Priority Scheduling (lower number = higher priority)
 Compile: gcc -o priority priority.c
*/
int main() {
    int n, bt[100], pr[100], p[100], wt[100], tat[100];
    int i,j,tmp;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Burst time of P%d: ", i+1);
        scanf("%d",&bt[i]);
        printf("Priority of P%d (lower number = higher priority): ", i+1);
        scanf("%d",&pr[i]);
        p[i]=i+1;
    }
    // sort by priority
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(pr[j] < pr[i]){
                tmp = pr[i]; pr[i] = pr[j]; pr[j] = tmp;
                tmp = bt[i]; bt[i] = bt[j]; bt[j] = tmp;
                tmp = p[i]; p[i] = p[j]; p[j] = tmp;
            }
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++) wt[i]=wt[i-1]+bt[i-1];
    for(i=0;i<n;i++) tat[i]=wt[i]+bt[i];
    printf("\nProcess\tBT\tPr\tWT\tTAT\n");
    for(i=0;i<n;i++) printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    return 0;
}
