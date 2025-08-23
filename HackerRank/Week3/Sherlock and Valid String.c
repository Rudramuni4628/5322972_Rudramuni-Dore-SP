#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* isValid(char* s) {
    int freq[26] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    int freqCount[len + 1];
    for (int i = 0; i <= len; i++)
        freqCount[i] = 0;

    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            freqCount[freq[i]]++;
            if (freq[i] > maxFreq)
                maxFreq = freq[i];
        }
    }

    int distinctFreq = 0;
    for (int i = 1; i <= maxFreq; i++) {
        if (freqCount[i] > 0)
            distinctFreq++;
    }

    if (distinctFreq == 1) {
        return "YES";
    }

    if (distinctFreq > 2) {
        return "NO";
    }

    int freq1 = 0, freq2 = 0;
    for (int i = 1; i <= maxFreq; i++) {
        if (freqCount[i] > 0) {
            if (freq1 == 0)
                freq1 = i;
            else
                freq2 = i;
        }
    }

    int count1 = freqCount[freq1];
    int count2 = freqCount[freq2];

    if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
        return "YES";
    }

    if ((freq1 - freq2 == 1 && count1 == 1) || (freq2 - freq1 == 1 && count2 == 1)) {
        return "YES";
    }

    return "NO";
}

int main() {
    char s[100001];  // Accommodate large input up to 100k chars as per typical constraints
    scanf("%s", s);
    printf("%s\n", isValid(s));
    return 0;
}