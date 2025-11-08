#include <stdio.h>

int mutex = 1;
int full = 0;
int empty = 3;
int x = 0;      

void wait(int *s) {
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void producer() {
    wait(&mutex);
    wait(&empty);
    x++;
    printf("\nProducer produces item %d", x);
    signal(&full);
    signal(&mutex);
}

void consumer() {
    wait(&mutex);
    wait(&full);
    printf("\nConsumer consumes item %d", x);
    x--;
    signal(&empty);
    signal(&mutex);
}

int main() {
    int choice;
    printf("Producer-Consumer Problem Simulation\n");
    while (1) {
        printf("\n\n1. Produce\n2. Consume\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("\nBuffer is full!");
                break;

            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("\nBuffer is empty!");
                break;

            case 3:
                return 0;

            default:
                printf("\nInvalid choice!");
        }
    }
}
