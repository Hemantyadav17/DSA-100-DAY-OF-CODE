//Problem Statement:
//Construct a binary tree from given inorder and postorder traversal arrays.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

// Create node
Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Search in inorder
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree
Node* buildTree(int inorder[], int postorder[],
                int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    // Last element in postorder = root
    Node* root = newNode(postorder[*postIndex]);
    (*postIndex)--;

    // If leaf node
    if (start == end)
        return root;

    // Find root in inorder
    int inIndex = search(inorder, start, end, root->val);

    // IMPORTANT: build right first
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

// -------- MAIN --------
int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}