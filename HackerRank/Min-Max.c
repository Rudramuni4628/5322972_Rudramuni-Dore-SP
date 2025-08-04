void miniMaxSum(int arr_count, int* arr) {
    long result = 0;
    int min = INT_MAX, max = INT_MIN;
    
    for(int i=0;i<arr_count;i++){
        if(arr[i]<min)
        min=arr[i];
        if(arr[i]>max)
        max=arr[i];
        result += arr[i];
    }
    printf("%ld %ld\n", result-max,result-min);
    

}
