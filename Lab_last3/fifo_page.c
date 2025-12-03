#include <stdio.h>

/*
 FIFO Page Replacement
 Compile: gcc -o fifo_page fifo_page.c
*/
void FIFO(int pages[], int n, int frame_size) {
    int frames[frame_size], i, j, fault = 0, index = 0;
    for(i=0;i<frame_size;i++) frames[i] = -1;
    for(i=0;i<n;i++){
        int found = 0;
        for(j=0;j<frame_size;j++) if(frames[j]==pages[i]) { found=1; break; }
        if(!found){
            frames[index] = pages[i];
            index = (index + 1) % frame_size;
            fault++;
        }
        printf("After page %d: ", pages[i]);
        for(j=0;j<frame_size;j++) (frames[j]==-1)? printf(" _ "): printf(" %d ", frames[j]);
        printf(found ? "  (Hit)\n":"  (Fault)\n");
    }
    printf("\\nTotal Page Faults (FIFO) = %d\\n", fault);
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
    FIFO(pages,n,fs);
    return 0;
}
