#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Structure to represent the stack
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push element %d\n", value);
    } else {
        s->arr[++s->top] = value;
        printf("Element %d pushed onto the stack\n", value);
    }
}

// Function to pop an element from the stack
void pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
    } else {
        printf("Element %d popped from the stack\n", s->arr[s->top--]);
    }
}

// Function to display the status of the stack
void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack status: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int choice, element;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                break;

            case 2:
                pop(&stack);
                break;

            case 3:
                display(&stack);
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
