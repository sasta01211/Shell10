#include <stdio.h>

/*
 Second Chance (Clock) Page Replacement
 Each frame has a reference bit; on fault, give a second chance by clearing ref bit and moving on.
 Compile: gcc -o second_chance second_chance.c
*/
void SecondChance(int pages[], int n, int frame_size) {
    int frames[frame_size], ref[frame_size], i, j, fault=0, ptr=0;
    for(i=0;i<frame_size;i++){ frames[i]=-1; ref[i]=0; }
    for(i=0;i<n;i++){
        int cur = pages[i];
        int hit = 0;
        for(j=0;j<frame_size;j++) if(frames[j]==cur){ hit=1; ref[j]=1; break; }
        if(!hit){
            // find victim
            while(1){
                if(frames[ptr]==-1){
                    // empty slot -> use it
                    frames[ptr]=cur; ref[ptr]=1; ptr = (ptr+1)%frame_size; break;
                }
                if(ref[ptr]==0){
                    // replace this one
                    frames[ptr]=cur; ref[ptr]=1; ptr = (ptr+1)%frame_size; break;
                } else {
                    // give second chance
                    ref[ptr]=0;
                    ptr = (ptr+1)%frame_size;
                }
            }
            fault++;
        }
        printf("After page %d: ", cur);
        for(j=0;j<frame_size;j++) (frames[j]==-1)? printf(" _ "): printf(" %d(%d) ", frames[j], ref[j]);
        printf(hit ? "  (Hit)\n":"  (Fault)\n");
    }
    printf("\\nTotal Page Faults (SecondChance) = %d\\n", fault);
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
    SecondChance(pages,n,fs);
    return 0;
}
