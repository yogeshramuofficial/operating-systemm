#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[8]={98,183,41,122,14,124,65,67}, head=53, total=0;
    int left[9], right[9], l=0, r=0, disk=200;

    for(int i=0;i<8;i++) (req[i]<head?left[l++]:right[r++]=req[i]);
    left[l++]=0; right[r++]=disk-1;

    for(int i=0;i<l-1;i++) for(int j=i+1;j<l;j++) if(left[i]>left[j]){int t=left[i]; left[i]=left[j]; left[j]=t;}
    for(int i=0;i<r-1;i++) for(int j=i+1;j<r;j++) if(right[i]>right[j]){int t=right[i]; right[i]=right[j]; right[j]=t;}

    printf("C-SCAN Disk Scheduling\n");
    for(int i=0;i<r;i++){ int s=abs(head-right[i]); total+=s; printf("%d->%d, Seek=%d\n", head,right[i],s); head=right[i]; }
    total+=head; printf("Jump %d->0, Seek=%d\n", head, head); head=0;
    for(int i=0;i<l-1;i++){ int s=abs(head-left[i]); total+=s; printf("%d->%d, Seek=%d\n", head,left[i],s); head=left[i]; }

    printf("Total Seek=%d\n", total);
    return 0;
}
