    #include <stdio.h>
    #define MAX_SIZE 100
    typedef struct {
        int items[MAX_SIZE];
        int front;
        int rear;
    } Queue;
    void enqueue(Queue *queue, int value);
    void dequeue(Queue *queue);
    void displayQueue(Queue *queue);
    int main() {
        Queue myQueue;
        myQueue.front = -1;
        myQueue.rear = -1;
        enqueue(&myQueue, 10);
        enqueue(&myQueue, 20);
        enqueue(&myQueue, 30);
        enqueue(&myQueue, 40);
        printf("Queue elements before deletion: ");
        displayQueue(&myQueue);
        dequeue(&myQueue);
        printf("Queue elements after deletion: ");
        displayQueue(&myQueue);
        return 0;
    }
    void enqueue(Queue *queue, int value) {
        if (queue->rear == MAX_SIZE - 1) {
            printf("Queue is full. Unable to enqueue.\n");
        } else {
            if (queue->front == -1) {
                queue->front = 0;
            }
            queue->rear++;
            queue->items[queue->rear] = value;
            printf("%d enqueued successfully.\n", value);
        }
    }
    void dequeue(Queue *queue) {
        if (queue->front == -1) {
            printf("Queue is empty. Unable to dequeue.\n");
        } else {
            int deletedValue = queue->items[queue->front];
            printf("%d dequeued successfully.\n", deletedValue);

            if (queue->front == queue->rear) {
                queue->front = -1;
                queue->rear = -1;
            } else {
                queue->front++;
            }
        }
    }
    void displayQueue(Queue *queue) {
        if (queue->rear == -1) {
            printf("Queue is empty.\n");
        } else {
            for (int i = queue->front; i <= queue->rear; i++) {
                printf("%d ", queue->items[i]);
            }
            printf("\n");
        }
    }

