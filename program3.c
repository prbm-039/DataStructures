#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Structure to represent the queue
struct Queue {
    int arr[MAX];
    int front, rear;
};

// Function to initialize the queue
void initialize(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to insert an element into the queue
void insert(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert element %d\n", value);
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = value;
        printf("Element %d inserted into the queue\n", value);
    }
}

// Function to delete an element from the queue
void delete(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot delete from an empty queue\n");
    } else {
        printf("Element %d deleted from the queue\n", q->arr[q->front]);
        if (q->front == q->rear) {
            // If the queue becomes empty after deletion
            initialize(q);
        } else {
            q->front = (q->front + 1) % MAX;
        }
    }
}

// Function to display the status of the queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue status: ");
        int i = q->front;
        do {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX;
        } while (i != (q->rear + 1) % MAX);
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);

    int choice, element;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(&queue, element);
                break;

            case 2:
                delete(&queue);
                break;

            case 3:
                display(&queue);
                break;

            case 4:
                printf("Exiting program\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (1);  // Infinite loop for the menu

    return 0;
}
