#include <stdio.h>
#define MAX_SIZE 100
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Deque;
int deleteFront(Deque* deque) {
    if (deque->front == -1) {
        printf("Deque is empty. Unable to delete from the front.\n");
        return -1; // Returning -1 indicates an error or an empty deque
    }
    int deletedValue = deque->items[deque->front];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front++;
    }
    return deletedValue;
}
int deleteRear(Deque* deque) {
    if (deque->rear == -1) {
        printf("Deque is empty. Unable to delete from the rear.\n");
        return -1; // Returning -1 indicates an error or an empty deque
    }
    int deletedValue = deque->items[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = -1; deque->rear = -1;
    } else {
        deque->rear--;
    }
    return deletedValue;
}
int main() {
    Deque myDeque;
    myDeque.front = 0;
    myDeque.rear = 3;
    myDeque.items[0] = 40;
    myDeque.items[1] = 70;
    myDeque.items[2] = 20;
    myDeque.items[3] = 90;
    printf("Deque elements before deletion: %d %d %d %d\n",
           myDeque.items[0], myDeque.items[1], myDeque.items[2], myDeque.items[3]);
    int deletedFront = deleteFront(&myDeque);
    if (deletedFront != -1) {
        printf("Deleted element from the front: %d\n", deletedFront);
    }
    int deletedRear = deleteRear(&myDeque);
    if (deletedRear != -1) {
        printf("Deleted element from the rear: %d\n", deletedRear);
    }
    printf("Deque elements after deletion: %d %d\n", myDeque.items[myDeque.front],
           myDeque.items[myDeque.rear]);
    return 0;
}
