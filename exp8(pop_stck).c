#include <stdio.h>
#define MAX_SIZE 10
int stack[MAX_SIZE];
int top = -1;
void push(int value) {
    if (top >= MAX_SIZE - 1) {
            printf("Error: Stack overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}
int main() {
    push(10);
    push(12);
    push(22);
    push(07);
    push(4);
    push(32);
    push(19);
    printf("Stack Elements are : ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
    return 0;
    }

