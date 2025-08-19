char* balancedSums(int arr_count, int* arr) {
    int total_sum = 0;
    for (int i = 0; i < arr_count; i++) {
        total_sum += arr[i];
    }

    int left_sum = 0;
    for (int i = 0; i < arr_count; i++) {
        int right_sum = total_sum - arr[i] - left_sum;
        if (left_sum == right_sum) {
            return "YES";
        }
        left_sum += arr[i];
    }
    return "NO";

}
