// A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien
//language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.
//Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid,
//return a string containing the unique letters in lexicographically increasing order as per the new language's rules.
//If there are multiple valid orders, return any one of them. However, if the given arrangement of words is inconsistent with any 
//possible letter ordering, return an empty string (""). A string a is lexicographically smaller than a string b if, at the first position
// where they differ, the character in a appears earlier in the alien language than the corresponding character in b. 
//If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char words[500][101];

    for (int i = 0; i < n; i++)
        scanf("%s", words[i]);

    int adj[26][26] = {0};
    int indegree[26] = {0};
    int present[26] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        char *a = words[i];
        char *b = words[i + 1];

        int len = strlen(a) < strlen(b) ? strlen(a) : strlen(b);
        int found = 0;

        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                int u = a[j] - 'a';
                int v = b[j] - 'a';

                if (!adj[u][v]) {
                    adj[u][v] = 1;
                    indegree[v]++;
                }

                found = 1;
                break;
            }
        }

        if (!found && strlen(a) > strlen(b)) {
            printf("Invalid Order\n");
            return 0;
        }
    }

    int queue[26];
    int front = 0, rear = 0;

    for (int i = 0; i < 26; i++) {
        if (present[i] && indegree[i] == 0)
            queue[rear++] = i;
    }

    char result[27];
    int idx = 0;

    while (front < rear) {
        int node = queue[front++];
        result[idx++] = node + 'a';

        for (int i = 0; i < 26; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 26; i++)
        if (present[i]) count++;

    if (idx != count) {
        printf("Invalid Order\n");
    } else {
        result[idx] = '\0';
        printf("%s\n", result);
    }

    return 0;
}