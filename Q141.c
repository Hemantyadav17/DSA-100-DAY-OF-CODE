//Problem Statement
//Implement a hash table using quadratic probing with formula:

#include <stdio.h>

#define SIZE 100
#define EMPTY -1

int table[SIZE];

void init(int m) {
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;
}

int hash(int key, int m) {
    return key % m;
}

void insert(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i*i) % m;

        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }

    printf("Hash Table Full\n");
}

void search(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i*i) % m;

        if (table[idx] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    init(m);

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I')
            insert(key, m);
        else
            search(key, m);
    }

    return 0;
}