#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
typedef struct {
    int top;
    int arr[MAX_SIZE];
} Stack;

void push(Stack *stack, int val) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->top++;
    stack->arr[stack->top] = val;
}
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(1);}
    int val = stack->arr[stack->top];
    stack->top--;
    return val;
}
int evaluate_postfix(char *expr) {
    Stack stack = { -1, {0} };
    int i, val;
for (i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            push(&stack, expr[i] - '0');
                    } else {
            int op2 = pop(&stack);
            int op1 = pop(&stack);

            switch (expr[i]) {
                case '+':
                    val = op1 + op2;
                    break;
                case '-':
                    val = op1 - op2;
                    break;
                case '*':
                    val = op1 * op2;
                    break;
                case '/':
                    val = op1 / op2;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }

            push(&stack, val);
        }
    }
    return pop(&stack);
}
int main() {
    char expr[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", expr);
    int result = evaluate_postfix(expr);
    printf("Result: %d\n", result);
    return 0;
}

