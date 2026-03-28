//Problem Statement:
//Check whether a given binary tree is symmetric around its center.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

// Create new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree from array (level order)
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node* nodes[n];

    // Create nodes / NULL
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    // Link children
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];
            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

// Check mirror
int isMirror(Node* a, Node* b) {
    if (a == NULL && b == NULL)
        return 1;
    if (a == NULL || b == NULL)
        return 0;

    return (a->val == b->val &&
            isMirror(a->left, b->right) &&
            isMirror(a->right, b->left));
}

// Check symmetric
int isSymmetric(Node* root) {
    return isMirror(root, root);
}

// -------- MAIN --------
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}