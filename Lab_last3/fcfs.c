#include <stdio.h>

/*
 FCFS Scheduling (assumes arrival time = 0 for all)
 Compile: gcc -o fcfs fcfs.c
*/
int main() {
    int n, bt[100], wt[100], tat[100], i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter burst times:\n");
    for(i = 0; i < n; i++){
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for(i = 1; i < n; i++) wt[i] = wt[i-1] + bt[i-1];
    for(i = 0; i < n; i++) tat[i] = wt[i] + bt[i];
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    return 0;
}
