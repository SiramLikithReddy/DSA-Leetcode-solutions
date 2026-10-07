#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

void push(struct Stack *stack, int value) {
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = stack->top;
    stack->top = newnode;
}

int pop(struct Stack *stack) {
    if (stack->top == NULL) return '\0';
    int value = stack->top->data;
    struct Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

int main() {
    struct Stack stack;
    stack.top = NULL;
    int a[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = 8;
    int result[8] = {0};

    for (int i = 0; i < n; i++) {
        while (stack.top != NULL && a[i] > a[stack.top->data]) {
            int prev_index = pop(&stack);
            result[prev_index] = i - prev_index;
        }
        push(&stack, i);
    }

    for (int k = 0; k < n; k++) {
        printf("%d,", result[k]);
    }

    return 0;
}
