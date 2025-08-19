char* caesarCipher(char* s, int k) {
    int len = strlen(s);
    int shift = k % 26;  // Normalize shift within 0-25

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (isalpha(c)) {
            if (islower(c)) {
                s[i] = ((c - 'a' + shift) % 26) + 'a';
            } else { // uppercase letter
                s[i] = ((c - 'A' + shift) % 26) + 'A';
            }
        }
        // non-alphabetic characters remain unchanged
    }

    return s;

}
