int cmpfunc(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    if (int_a < int_b) return -1;
    else if (int_a > int_b) return 1;
    else return 0;
}
int maxMin(int k, int arr_count, int* arr) {
    qsort(arr, arr_count, sizeof(int), cmpfunc);

    int min_unfairness = arr[k - 1] - arr[0];

    for (int i = 1; i <= arr_count - k; i++) {
        int diff = arr[i + k - 1] - arr[i];
        if (diff < min_unfairness) {
            min_unfairness = diff;
        }
    }

    return min_unfairness;

}
