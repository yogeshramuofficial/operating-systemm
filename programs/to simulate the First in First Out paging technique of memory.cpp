#include <stdio.h>

int main() {
    int i, j, n, frames, pageFaults = 0, flag;
    int pages[20], memory[10], front = 0;

 
    n = 12; 
    int examplePages[12] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    frames = 3; 

   
    for (i = 0; i < n; i++)
        pages[i] = examplePages[i];

 
    for (i = 0; i < frames; i++)
        memory[i] = -1; 

    printf("Page Reference String: ");
    for (i = 0; i < n; i++)
        printf("%d ", pages[i]);
    printf("\n\n");

   
    for (i = 0; i < n; i++) {
        flag = 0;

      
        for (j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                flag = 1; 
                break;
            }
        }

   
        if (flag == 0) {
            memory[front] = pages[i];       
            front = (front + 1) % frames;   
            pageFaults++;
        }

       
        printf("After accessing page %d: ", pages[i]);
        for (j = 0; j < frames; j++)
            if (memory[j] != -1)
                printf("%d ", memory[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}
