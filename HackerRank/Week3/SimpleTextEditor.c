#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPS 100000
#define MAX_LEN 1000000

typedef struct Stack {
    char **data;
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s, int capacity) {
    s->data = malloc(sizeof(char*) * capacity);
    s->top = -1;
}

// Push a copy of string onto stack
void push(Stack *s, const char *str) {
    s->data[++s->top] = strdup(str);
}

// Pop string from stack and return it
char* pop(Stack *s) {
    if (s->top == -1) return NULL;
    char* res = s->data[s->top--];
    return res;
}

// Peek top of stack without popping
char* peek(Stack *s) {
    if (s->top == -1) return NULL;
    return s->data[s->top];
}

// Free all allocated strings in stack
void freeStack(Stack *s) {
    while (s->top >= 0) free(s->data[s->top--]);
    free(s->data);
}

int main() {
    int Q;
    scanf("%d", &Q);
    char *current = calloc(1, 1); // initially empty string
    Stack undoStack;
    initStack(&undoStack, Q);

    for (int i = 0; i < Q; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            // append w
            char w[100001];
            scanf("%s", w);
            push(&undoStack, current);

            int len_cur = strlen(current);
            int len_w = strlen(w);
            current = realloc(current, len_cur + len_w + 1);
            strcpy(current + len_cur, w);
        } 
        else if (op == 2) {
            // delete k
            int k;
            scanf("%d", &k);
            push(&undoStack, current);

            int len_cur = strlen(current);
            current[len_cur - k] = '\0';
            // shrink memory is optional
            current = realloc(current, strlen(current) + 1);
        } 
        else if (op == 3) {
            // print k-th char
            int k;
            scanf("%d", &k);
            printf("%c\n", current[k -1]);
        } 
        else if (op == 4) {
            // undo last append or delete
            free(current);
            current = pop(&undoStack);
            if (current == NULL) {
                // No operation to undo; make string empty
                current = calloc(1,1);
            }
        }
    }

    free(current);
    freeStack(&undoStack);
    return 0;
}
