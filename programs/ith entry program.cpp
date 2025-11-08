#include <stdio.h>

int main() {
    int indexBlock[5] = {101,102,103,104,105};

    printf("Indexed File Allocation Simulation\n");
    for(int i=0;i<5;i++)
        printf("Accessing Block %d: Physical Block %d\n", i+1, indexBlock[i]);

    return 0;
}
