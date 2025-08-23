#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to copy grid
char** copy_grid(char** src, int rows, int cols) {
    char** dst = malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; ++i) {
        dst[i] = malloc(cols + 1);
        strcpy(dst[i], src[i]);
    }
    return dst;
}

// Simulate one detonation step
char** detonate(char** grid, int rows, int cols) {
    char** result = malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; ++i) {
        result[i] = malloc(cols + 1);
        for (int j = 0; j < cols; ++j)
            result[i][j] = 'O';
        result[i][cols] = '\0';
    }
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (grid[i][j] == 'O') {
                result[i][j] = '.';
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dr[d], nj = j + dc[d];
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols)
                        result[ni][nj] = '.';
                }
            }
    return result;
}

// Main solution function
char** bomberMan(int n, int grid_count, char** grid, int* result_count) {
    int rows = grid_count;
    int cols = strlen(grid[0]);
    *result_count = rows;

    if (n == 1) {
        return copy_grid(grid, rows, cols);
    }
    if (n % 2 == 0) {
        char** filled = malloc(rows * sizeof(char*));
        for (int i = 0; i < rows; ++i) {
            filled[i] = malloc(cols + 1);
            for (int j = 0; j < cols; ++j)
                filled[i][j] = 'O';
            filled[i][cols] = '\0';
        }
        return filled;
    }

    // n is odd and > 1
    char** first = detonate(grid, rows, cols);
    char** second = detonate(first, rows, cols);

    char** result;
    // Time cycles: n=3,7,11,... use first; n=5,9,13,.. use second.
    if (((n - 3) / 2) % 2 == 0) {
        result = first;
        for (int i = 0; i < rows; ++i)
            free(second[i]);
        free(second);
    } else {
        result = second;
        for (int i = 0; i < rows; ++i)
            free(first[i]);
        free(first);
    }
    return result;
}

int main() {
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    char **grid = malloc(r * sizeof(char*));
    char buff[210];
    for (int i = 0; i < r; ++i) {
        scanf("%s", buff);
        grid[i] = malloc(c + 1);
        strcpy(grid[i], buff);
    }
    int result_count;
    char **result = bomberMan(n, r, grid, &result_count);
    for (int i = 0; i < result_count; ++i) {
        printf("%s\n", result[i]);
        free(result[i]);
        free(grid[i]);
    }
    free(result);
    free(grid);
    return 0;
}