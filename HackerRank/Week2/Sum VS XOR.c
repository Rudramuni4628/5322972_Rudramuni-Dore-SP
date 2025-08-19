long sumXor(long n) {
    if (n == 0) return 1;

    int zero_bits = 0;
    long long temp = n;

    while (temp > 0) {
        if ((temp & 1) == 0)
            zero_bits++;
        temp >>= 1;
    }

    return 1LL << zero_bits;

}