#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isMatching(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

char* isBalanced(char* s) {
    int len = strlen(s);
    char* stack = malloc(len);
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }
        else {
            if (top == -1) {
                free(stack);
                return "NO";
            }
            if (!isMatching(stack[top], c)) {
                free(stack);
                return "NO";
            }
            top--;
        }
    }
    free(stack);
    return (top == -1) ? "YES" : "NO";
}

int main() {
    int n;
    scanf("%d", &n);
    char input[1000];
    for (int i = 0; i < n; i++) {
        scanf("%s", input);
        printf("%s\n", isBalanced(input));
    }
    return 0;
}