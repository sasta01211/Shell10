#include <stdio.h>
#include <stdbool.h>

/*
 Banker's algorithm (deadlock avoidance)
 Compile: gcc -o bankers bankers.c
 Input: enter number of processes (n) and resources (m), then matrices:
 Allocation (n x m), Max (n x m), Available (m)
*/
int main() {
    int n, m, i, j;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resource types: ");
    scanf("%d",&m);

    int alloc[20][20], max[20][20], need[20][20], avail[20];
    for(i=0;i<n;i++){
        printf("Enter allocation for P%d (space separated %d values): ", i+1, m);
        for(j=0;j<m;j++) scanf("%d",&alloc[i][j]);
    }
    for(i=0;i<n;i++){
        printf("Enter max for P%d (space separated %d values): ", i+1, m);
        for(j=0;j<m;j++) scanf("%d",&max[i][j]);
    }
    printf("Enter available resources (space separated %d values): ", m);
    for(j=0;j<m;j++) scanf("%d",&avail[j]);

    // compute need = max - alloc
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Banker's safety algorithm
    bool finish[20] = {0};
    int safeSeq[20], idx = 0;
    int work[20];
    for(j=0;j<m;j++) work[j]=avail[j];

    for(int cnt=0; cnt<n; cnt++){
        bool progressed = false;
        for(i=0;i<n;i++){
            if(!finish[i]){
                bool ok = true;
                for(j=0;j<m;j++) if(need[i][j] > work[j]) { ok = false; break; }
                if(ok){
                    // this process can finish
                    for(j=0;j<m;j++) work[j] += alloc[i][j];
                    safeSeq[idx++] = i;
                    finish[i] = true;
                    progressed = true;
                }
            }
        }
        if(!progressed) break;
    }

    bool safe = true;
    for(i=0;i<n;i++) if(!finish[i]) safe = false;

    if(safe){
        printf("System is in a safe state.\nSafe sequence: ");
        for(i=0;i<idx;i++) printf("P%d ", safeSeq[i]+1);
        printf("\n");
    } else {
        printf("System is NOT in a safe state (unsafe / potential deadlock).\n");
    }
    return 0;
}
