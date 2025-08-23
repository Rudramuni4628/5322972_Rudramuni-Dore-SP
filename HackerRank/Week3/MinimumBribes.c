void minimumBribes(int q_count, int* q) {
     int bribes = 0;

    for (int i = 0; i < q_count; i++) {
        // Check if current person has moved more than two places forward
        if (q[i] - (i + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }
    }