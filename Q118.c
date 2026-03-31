// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree 
//and postorder is the postorder traversal of the same tree, construct and return the binary tree.

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

int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

Node* build(int inorder[], int postorder[],
            int start, int end, int* postIndex) {
    if (start > end) return NULL;

    Node* root = newNode(postorder[*postIndex]);
    (*postIndex)--;

    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, root->val);

    // Right first
    root->right = build(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = build(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Print level order (like LeetCode output)
void printLevelOrder(Node* root) {
    if (!root) return;

    Node* queue[3000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* curr = queue[front++];
        printf("%d ", curr->val);

        if (curr->left)
            queue[rear++] = curr->left;
        if (curr->right)
            queue[rear++] = curr->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    Node* root = build(inorder, postorder, 0, n - 1, &postIndex);

    printLevelOrder(root);

    return 0;
}