#include <stdio.h>
#include <stdlib.h>

// Dynamic array structure
typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

// Initialize dynamic array
void initArray(DynamicArray *arr) {
    arr->size = 0;
    arr->capacity = 2;
    arr->data = (int *)malloc(arr->capacity * sizeof(int));
}

// Append value to dynamic array
void append(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size++] = value;
}

// Get element at index
int get(DynamicArray *arr, int index) {
    return arr->data[index];
}

// Free dynamic array memory
void freeArray(DynamicArray *arr) {
    free(arr->data);
}

// Main function solving the problem
int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    DynamicArray *arrs = (DynamicArray *)malloc(n * sizeof(DynamicArray));
    for (int i = 0; i < n; i++) {
        initArray(&arrs[i]);
    }
    
    int lastAnswer = 0;
    int *results = (int *)malloc(queries_rows * sizeof(int)); // max possible size
    int res_index = 0;

    for (int i = 0; i < queries_rows; i++) {
        int t = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        int idx = (x ^ lastAnswer) % n;

        if (t == 1) {
            append(&arrs[idx], y);
        } else if (t == 2) {
            int val = get(&arrs[idx], y % arrs[idx].size);
            lastAnswer = val;
            results[res_index++] = lastAnswer;
        }
    }

    for (int i = 0; i < n; i++) {
        freeArray(&arrs[i]);
    }
    free(arrs);

    *result_count = res_index;
    return results;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int** queries = (int**)malloc(q * sizeof(int*));
    for (int i = 0; i < q; i++) {
        queries[i] = (int*)malloc(3 * sizeof(int));
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
    }

    int result_count = 0;
    int *results = dynamicArray(n, q, 3, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", results[i]);
    }

    free(results);
    for (int i = 0; i < q; i++) free(queries[i]);
    free(queries);

    return 0;
}