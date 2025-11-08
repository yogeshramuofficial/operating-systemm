#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[8]={98,183,41,122,14,124,65,67}, head=53, total=0;

    printf("FCFS Disk Scheduling\nInitial Head: %d\n", head);
    for(int i=0;i<8;i++){
        int seek=abs(head-requests[i]);
        total+=seek;
        printf("Move %d->%d, Seek=%d\n", head, requests[i], seek);
        head=requests[i];
    }
    printf("Total Seek=%d\n", total);
    return 0;
}
