//queue
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
// Structure to represent a queue
struct Queue {
    int front, rear;
    int arr[MAX_SIZE];
};
// Function to create a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (!q) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    q->front = -1;
    q->rear = -1;
    return q;
}
// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}
// Function to check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}
// Function to enqueue an element
void enqueue(struct Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->arr[q->rear] = data;
    printf("Enqueued: %d\n", data);
}
// Function to dequeue an element
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1; // Return an error value
    }
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // If only one element, reset both pointers
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    printf("Dequeued: %d\n", data);
    return data;
}
// Function to display the elements of the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    do {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (q->rear + 1) % MAX_SIZE);
    printf("\n");
}
int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    // Cleanup memory
    free(q);
    return 0;
}

