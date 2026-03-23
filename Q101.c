//Problem Statement:
//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        // If both smaller → go left
        if (n1 < root->data && n2 < root->data)
            root = root->left;

        // If both greater → go right
        else if (n1 > root->data && n2 > root->data)
            root = root->right;

        // Otherwise → this is LCA
        else
            return root;
    }
    return NULL;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Node* root = NULL;

    // Input BST nodes
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}