#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

// Initialize stack
void init(Stack* s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push item onto stack
void push(Stack* s, int item) {
    if (s->top < MAX - 1) {
        s->items[++s->top] = item;
    }
}

// Pop item from stack
int pop(Stack* s) {
    if (isEmpty(s)) return -1; // or handle error
    return s->items[s->top--];
}

// Peek top item without popping
int peek(Stack* s) {
    if (isEmpty(s)) return -1; // or handle error
    return s->items[s->top];
}

int main() {
    int q;
    scanf("%d", &q);

    Stack stackEnqueue, stackDequeue;
    init(&stackEnqueue);
    init(&stackDequeue);

    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            // Enqueue
            int x;
            scanf("%d", &x);
            push(&stackEnqueue, x);
        } else if (type == 2) {
            // Dequeue
            if (isEmpty(&stackDequeue)) {
                // Transfer all from enqueue stack to dequeue stack
                while (!isEmpty(&stackEnqueue)) {
                    push(&stackDequeue, pop(&stackEnqueue));
                }
            }
            pop(&stackDequeue);  // Remove front element
        } else if (type == 3) {
            // Print front element
            if (isEmpty(&stackDequeue)) {
                while (!isEmpty(&stackEnqueue)) {
                    push(&stackDequeue, pop(&stackEnqueue));
                }
            }
            int front = peek(&stackDequeue);
            if (front != -1) {
                printf("%d\n", front);
            }
        }
    }

    return 0;
}