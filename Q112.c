// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 #include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from array
Node* buildTree(int arr[], int n) {
    if (arr[0] == -1) return NULL;

    Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;

            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

int isMirror(Node* a, Node* b) {
    if (a == NULL && b == NULL) return 1;
    if (a == NULL || b == NULL) return 0;

    return (a->val == b->val &&
            isMirror(a->left, b->right) &&
            isMirror(a->right, b->left));
}

int isSymmetric(Node* root) {
    return isMirror(root, root);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    if (isSymmetric(root))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}