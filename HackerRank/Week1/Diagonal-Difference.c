int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int psum=0,ssum=0;
    
    if(arr_rows != arr_columns){
        return 0;
    }
    
    for (int i=0;i<arr_rows;i++){
        psum += arr[i][i];
        ssum += arr[i][arr_columns-1-i];
        
    }
    return abs(psum-ssum);
}