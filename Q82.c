// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n.
// Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint:
// there has to be a gap of at least n intervals between two tasks with the same label.

#include <stdio.h>

int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};

    for(int i = 0; i < size; i++)
        freq[tasks[i] - 'A']++;

    int maxFreq = 0;
    for(int i = 0; i < 26; i++)
        if(freq[i] > maxFreq)
            maxFreq = freq[i];

    int maxCount = 0;
    for(int i = 0; i < 26; i++)
        if(freq[i] == maxFreq)
            maxCount++;

    int partCount = maxFreq - 1;
    int partLength = n - (maxCount - 1);
    int emptySlots = partCount * partLength;
    int availableTasks = size - maxFreq * maxCount;
    int idles = emptySlots - availableTasks;

    if(idles < 0) idles = 0;

    return size + idles;
}

int main() {
    int n, size;

    scanf("%d", &size);

    char tasks[size];
    for(int i = 0; i < size; i++)
        scanf(" %c", &tasks[i]);

    scanf("%d", &n);

    printf("%d", leastInterval(tasks, size, n));

    return 0;
}