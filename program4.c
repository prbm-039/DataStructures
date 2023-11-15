#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

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
    }
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return -1;
    } else {
        return s->arr[s->top--];
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initialize(&stack);

    int i, operand1, operand2, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0'); // Convert character to integer
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '%':
                    result = operand1 % operand2;
                    break;
                case '^':
                    result = (int)pow(operand1, operand2);
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", postfix[i]);
                    return -1;
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression with single-digit operands and operators (+, -, *, /, %, ^):\n");
    fgets(postfix, MAX, stdin);

    int result = evaluatePostfix(postfix);

    if (result != -1) {
        printf("Result of the postfix expression: %d\n", result);
    } else {
        printf("Error in evaluating the postfix expression.\n");
    }

    return 0;
}
