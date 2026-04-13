// Problem Statement
//Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated 
//if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.


#include <stdio.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        if (freq[idx] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }

        freq[idx]++;
    }

    printf("-1\n");
    return 0;
}