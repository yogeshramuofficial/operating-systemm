#include <stdio.h>
#include <sys/stat.h>

void printPermissions(mode_t mode) {
    printf("Owner:   %c%c%c\n",
           (mode & S_IRUSR) ? 'r' : '-',
           (mode & S_IWUSR) ? 'w' : '-',
           (mode & S_IXUSR) ? 'x' : '-');

    printf("Group:   %c%c%c\n",
           (mode & S_IRGRP) ? 'r' : '-',
           (mode & S_IWGRP) ? 'w' : '-',
           (mode & S_IXGRP) ? 'x' : '-');

    printf("Others:  %c%c%c\n",
           (mode & S_IROTH) ? 'r' : '-',
           (mode & S_IWOTH) ? 'w' : '-',
           (mode & S_IXOTH) ? 'x' : '-');
}

int main() {
    const char *filename = "example.txt";
    struct stat fileStat;

    if(stat(filename, &fileStat) == -1) {
        perror("stat");
        return 1;
    }

    printf("Permissions for file: %s\n", filename);
    printPermissions(fileStat.st_mode);

    return 0;
}
