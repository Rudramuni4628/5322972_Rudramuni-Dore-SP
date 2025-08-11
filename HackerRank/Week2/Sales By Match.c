int sockMerchant(int n, int ar_count, int* ar) {
    int pairs = 0;
    int used[n];
    for (int i=0;i<n;i++) used[i]=0;
    
    for (int i=0;i<n;i++){
        if (used[i]) continue;
        int count = 1;
        for (int j=i+1;j<n;j++){
            if (ar[j]==ar[i] && !used[j]){
                count++;
                used[j]=1;
            }
        }
        pairs += count/2;
    }
    return pairs;
    
}
