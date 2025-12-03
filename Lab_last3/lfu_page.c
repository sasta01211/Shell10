#include <stdio.h>

/*
 LFU (Least Frequently Used) Page Replacement
 Counts frequencies and replaces the least frequently used page.
 Tie-breaker: choose the oldest among least-frequent.
 Compile: gcc -o lfu_page lfu_page.c
*/
void LFU(int pages[], int n, int frame_size) {
    int frames[frame_size], freq[frame_size], time_stamp[frame_size];
    int i,j, fault=0, t=0;
    for(i=0;i<frame_size;i++){ frames[i] = -1; freq[i]=0; time_stamp[i]=0; }
    for(i=0;i<n;i++){
        int cur = pages[i];
        int found = -1;
        for(j=0;j<frame_size;j++) if(frames[j]==cur) { found=j; break; }
        if(found!=-1){
            freq[found]++;
            time_stamp[found]=t++;
        } else {
            // find empty slot
            int slot=-1;
            for(j=0;j<frame_size;j++) if(frames[j]==-1){ slot=j; break; }
            if(slot==-1){
                // find least frequently used; tie break by oldest time_stamp (smallest)
                int minf = freq[0], idx = 0;
                for(j=1;j<frame_size;j++){
                    if(freq[j] < minf || (freq[j]==minf && time_stamp[j] < time_stamp[idx])){
                        minf = freq[j]; idx = j;
                    }
                }
                slot = idx;
            }
            frames[slot]=cur;
            freq[slot]=1;
            time_stamp[slot]=t++;
            fault++;
        }
        printf("After page %d: ", cur);
        for(j=0;j<frame_size;j++) (frames[j]==-1)? printf(" _ "): printf(" %d ", frames[j]);
        printf(found!=-1 ? "  (Hit)\n":"  (Fault)\n");
    }
    printf("\\nTotal Page Faults (LFU) = %d\\n", fault);
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
    LFU(pages,n,fs);
    return 0;
}
