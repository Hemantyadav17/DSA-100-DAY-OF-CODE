//Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree 
//and inorder is the inorder traversal of the same tree, construct and return the binary tree.

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

Node* build(int preorder[], int inorder[],
            int start, int end, int* preIndex) {
    if (start > end) return NULL;

    Node* root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, root->val);

    root->left = build(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = build(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Print level order (simple queue)
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

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    Node* root = build(preorder, inorder, 0, n - 1, &preIndex);

    printLevelOrder(root);

    return 0;
}