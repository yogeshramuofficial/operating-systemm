#include <stdio.h>

int main() {
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n = 12, frames = 3, memory[3] = {-1,-1,-1}, pageFaults=0;
    
    for(int i=0;i<n;i++){
        int hit=0;
        for(int j=0;j<frames;j++)
            if(memory[j]==pages[i]) { hit=1; break; }
        if(!hit){
            int furthest=-1, replace=0;
            for(int j=0;j<frames;j++){
                int nextUse=-1;
                for(int k=i+1;k<n;k++)
                    if(memory[j]==pages[k]) { nextUse=k; break; }
                if(nextUse==-1){ replace=j; break; }
                if(nextUse>furthest){ furthest=nextUse; replace=j; }
            }
            memory[replace]=pages[i];
            pageFaults++;
        }
        printf("Page %d -> [", pages[i]);
        for(int j=0;j<frames;j++) if(memory[j]!=-1) printf("%d ", memory[j]);
        printf("]\n");
    }
    printf("Total Page Faults = %d\n", pageFaults);
    return 0;
}
