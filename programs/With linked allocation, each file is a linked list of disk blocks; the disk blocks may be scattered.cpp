#include <stdio.h>

typedef struct Block {
    int blockNumber;
    struct Block* next;
} Block;

int main() {
    Block b3 = {109,NULL}, b2 = {105,&b3}, b1 = {101,&b2};
    Block *start=&b1, *end=&b3;

    printf("Linked File Allocation Simulation\n");
    for(Block* temp=start; temp!=NULL; temp=temp->next)
        printf("Block %d -> ", temp->blockNumber);
    printf("NULL\nFirst Block: %d, Last Block: %d\n", start->blockNumber, end->blockNumber);

    return 0;
}
