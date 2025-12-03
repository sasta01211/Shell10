#include <stdio.h>

/*
 Optimal Page Replacement (clairvoyant)
 Compile: gcc -o optimal_page optimal_page.c
*/
void Optimal(int pages[], int n, int frame_size) {
    int frames[frame_size], i, j, fault = 0;
    for(i=0;i<frame_size;i++) frames[i]=-1;
    for(i=0;i<n;i++){
        int found = 0;
        for(j=0;j<frame_size;j++) if(frames[j]==pages[i]) { found=1; break; }
        if(!found){
            int replace = -1, farthest = i;
            for(j=0;j<frame_size;j++){
                if(frames[j]==-1) { replace=j; break; }
                int next_use = i+1;
                while(next_use<n && frames[j]!=pages[next_use]) next_use++;
                if(next_use>farthest) { farthest=next_use; replace=j; }
            }
            frames[replace]=pages[i];
            fault++;
        }
        printf("After page %d: ", pages[i]);
        for(j=0;j<frame_size;j++) (frames[j]==-1)? printf(" _ "): printf(" %d ", frames[j]);
        printf(found ? "  (Hit)\n":"  (Fault)\n");
    }
    printf("\\nTotal Page Faults (Optimal) = %d\\n", fault);
}

int main(){
    int n, i, fs;
    printf("Enter number of pages in reference string: ");
    scanf("%d",&n);
    int pages[n];
    printf("Enter pages: ");
    for(i=0;i<n;i++) scanf("%d",&pages[i]);
    printf("Enter frame size: ");
    scanf("%d",&fs);
    Optimal(pages,n,fs);
    return 0;
}
