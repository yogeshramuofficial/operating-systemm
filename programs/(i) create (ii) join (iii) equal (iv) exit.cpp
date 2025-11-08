#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


void* myThread(void* arg) {
    printf("Thread %d is running\n", *(int*)arg);
    sleep(1); 
    printf("Thread %d is exiting\n", *(int*)arg);
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;
    int ret;

   
    ret = pthread_create(&t1, NULL, myThread, &id1);
    if (ret != 0) {
        printf("Error creating thread 1\n");
        exit(1);
    }

    ret = pthread_create(&t2, NULL, myThread, &id2);
    if (ret != 0) {
        printf("Error creating thread 2\n");
        exit(1);
    }

   
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

   
    if (pthread_equal(t1, t2))
        printf("Threads are equal\n");
    else
        printf("Threads are not equal\n");

   
    printf("Main thread exiting\n");
    pthread_exit(NULL); 

    return 0;
}
