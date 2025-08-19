int superDigit(char* n, int k) {
       int sum = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        sum = (sum + (n[i] - '0')) % 9;
    }

    sum = (sum * k) % 9;

    return sum == 0 ? 9 : sum;
}

int main1() {
    char n[100001]; // Large enough buffer for input string
    int k;

    scanf("%s %d", n, &k);

    int result = superDigit(n, k);
    printf("%d\n", result);

    return 0;

}