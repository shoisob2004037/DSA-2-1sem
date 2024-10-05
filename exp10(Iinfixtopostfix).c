#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

int getPrecedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '^')
        return 3;
    else
        return 0;
}

void infixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    initialize(&stack);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        if (isalnum(token))
            postfix[j++] = token;
        else if (token == '(')
            push(&stack, token);
        else if (token == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(')
                postfix[j++] = pop(&stack);

            if (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                printf("Invalid Expression\n");
                exit(EXIT_FAILURE);
            }
            pop(&stack);
        }
        else {
            while (!isEmpty(&stack) && getPrecedence(token) <= getPrecedence(stack.items[stack.top]))
                postfix[j++] = pop(&stack);
            push(&stack, token);
        }
    }

    while (!isEmpty(&stack))
        postfix[j++] = pop(&stack);

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

