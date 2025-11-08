#include <stdio.h>

int main() {
    char records[5][20] = {"Record_1","Record_2","Record_3","Record_4","Record_5"};
    int n = 5;

    printf("Sequential File Allocation Simulation\n");
    for(int i=0;i<n;i++)
        printf("Accessing record %d: %s\n", i+1, records[i]);

    return 0;
}
