int birthday(vector<int> s, int d, int m) {
    int count = 0;
    int n = s.size();
    for (int i = 0; i <= n - m; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += s[i + j];
        }
        if (sum == d)
            ++count;
    }
    return count;

}