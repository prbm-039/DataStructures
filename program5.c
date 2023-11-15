#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Structure to represent the stack
struct Stack {
    char arr[MAX];
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

// Function to push a character onto the stack
void push(struct Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push element %c\n", value);
    } else {
        s->arr[++s->top] = value;
    }
}

// Function to pop a character from the stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return '\0';
    } else {
        return s->arr[s->top--];
    }
}

// Function to get the precedence of an operator
int getPrecedence(char operator) {
    switch (operator) {
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);

    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, '(');
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && stack.arr[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.arr[stack.top] == '(') {
                pop(&stack); // Pop '(' from the stack
            } else {
                printf("Mismatched parentheses in the infix expression\n");
                exit(1);
            }
        } else {
            while (!isEmpty(&stack) && getPrecedence(infix[i]) <= getPrecedence(stack.arr[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    while (!isEmpty(&stack)) {
        if (stack.arr[stack.top] == '(') {
            printf("Mismatched parentheses in the infix expression\n");
            exit(1);
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression with operators: +, -, *, /, %, ^\n");
    fgets(infix, MAX, stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
