//Problem: BST Search

//Implement the solution for this problem.

#include <stdio.h>
#include <stdlib.h>

// Define Node structure
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

// Insert into BST (for testing)
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search in BST
struct Node* searchBST(struct Node* root, int key) {
    // Base case
    if (root == NULL || root->data == key)
        return root;

    // Go left
    if (key < root->data)
        return searchBST(root->left, key);

    // Go right
    return searchBST(root->right, key);
}

int main() {
    struct Node* root = NULL;

    // Build BST
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);

    int key = 4;

    struct Node* result = searchBST(root, key);

    if (result != NULL)
        printf("Value found in BST\n");
    else
        printf("Value not found in BST\n");

    return 0;
}