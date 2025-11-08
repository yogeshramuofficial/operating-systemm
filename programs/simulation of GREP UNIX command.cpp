#include <stdio.h>
#include <string.h>

int main() {
    char filename[100], pattern[100], line[500];
    FILE *fp;

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        return 1;
    }

    printf("\nLines containing '%s':\n", pattern);

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern)) { 
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}
