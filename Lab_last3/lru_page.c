#include <stdio.h>

/*
 LRU Page Replacement (uses 'used' timestamp)
 Compile: gcc -o lru_page lru_page.c
*/
void LRU(int pages[], int n, int frame_size) {
    int frames[frame_size], used[frame_size], i, j, fault = 0;
    for(i=0;i<frame_size;i++){ frames[i] = -1; used[i] = -1; }
    for(i=0;i<n;i++){
        int found = 0, current = pages[i];
        for(j=0;j<frame_size;j++){
            if(frames[j]==current){ found=1; used[j]=i; break; }
        }
        if(!found){
            int lru = 0;
            for(j=0;j<frame_size;j++){
                if(frames[j]==-1){ lru=j; break; }
                if(used[j] < used[lru]) lru=j;
            }
            frames[lru]=current;
            used[lru]=i;
            fault++;
        }
        printf("After page %d: ", current);
        for(j=0;j<frame_size;j++) (frames[j]==-1)? printf(" _ "): printf(" %d ", frames[j]);
        printf(found ? "  (Hit)\n":"  (Fault)\n");
    }
    printf("\\nTotal Page Faults (LRU) = %d\\n", fault);
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
    LRU(pages,n,fs);
    return 0;
}
