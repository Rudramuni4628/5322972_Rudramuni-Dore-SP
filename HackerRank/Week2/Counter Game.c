char* counterGame(long n) {
     int count = 0;

    // Helper macro to check if n is power of two
    #define isPowerOfTwo(x) ((x & (x - 1)) == 0)

    while (n != 1) {
        if (isPowerOfTwo(n)) {
            n >>= 1;  // divide by 2
        } else {
            // Find largest power of 2 less than n
            long p = 1L << 62;  // start from highest possible (for 64-bit)
            while (p > n) p >>= 1;
            n -= p;
        }
        count++;
    }

    // Odd count => Louise wins (starts first), else Richard
    return (count % 2) ? "Louise" : "Richard";

}
