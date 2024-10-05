#include <stdio.h>
#define MAX_SIZE 100
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Deque;
void insertFront(Deque *deque, int value);
void insertRear(Deque *deque, int value);
void displayDeque(Deque *deque);
int main() {
    Deque myDeque;
    myDeque.front = -1;
    myDeque.rear = -1;
    insertFront(&myDeque, 40);
    insertFront(&myDeque, 70);
    insertRear(&myDeque, 20);
    insertRear(&myDeque, 99);
    printf("Deque elements: ");
    displayDeque(&myDeque);
}
void insertFront(Deque *deque, int value) {
    if ((deque->front == 0 && deque->rear == MAX_SIZE - 1) ||
        (deque->front == deque->rear + 1)) {
        printf("Deque is full. Unable to insert at the front.\n");
    } else {
        if (deque->front == -1) {
            deque->front = 0;
            deque->rear = 0;
        } else if (deque->front == 0) {
            deque->front = MAX_SIZE - 1;
        }
        else {
            deque->front--;}
        deque->items[deque->front] = value;
        printf("%d inserted at the front successfully.\n", value);
    }
}
void insertRear(Deque *deque, int value) {
    if ((deque->front == 0 && deque->rear == MAX_SIZE - 1)|(deque->front == deque->rear + 1))
        {printf("Deque is full. Unable to insert at the rear.\n");}
        else {if (deque->rear == -1) {
            deque->front = 0;
            deque->rear = 0;
        }
        else if (deque->rear == MAX_SIZE - 1) {
            deque->rear = 0;
        } else {
            deque->rear++;}
        deque->items[deque->rear] = value;
        printf("%d inserted at the rear successfully.\n", value);
    }
}
void displayDeque(Deque*deque) {
    if (deque->front == -1) {
        printf("Deque is empty.\n");
    } else {
        int i = deque->front;
        while (i != deque->rear) {
            printf("%d ", deque->items[i]);
            i = (i + 1) % MAX_SIZE;
        } printf("%d\n", deque->items[i]);
    }
}
