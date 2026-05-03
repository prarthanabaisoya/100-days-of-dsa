#include <stdio.h>
#include <string.h>

char firstRepeated(char s[]) {
    int freq[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';
        freq[idx]++;

        if (freq[idx] == 2)
            return s[i];
    }

    return '\0';
}

int main() {
    char s[] = "abcaed";
    char res = firstRepeated(s);

    if (res != '\0')
        printf("%c\n", res);
    else
        printf("No repeated character\n");

    return 0;
}