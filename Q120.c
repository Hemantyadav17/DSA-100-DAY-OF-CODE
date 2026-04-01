// You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, 
//and its immediate children. Return the minimum number of cameras needed to monitor all nodes of the tree

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

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

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

int cameras = 0;

int dfs(Node* root) {
    if (root == NULL) return 1;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 2 || right == 2) {
        cameras++;
        return 0;
    }

    if (left == 0 || right == 0)
        return 1;

    return 2;
}

int minCameraCover(Node* root) {
    if (dfs(root) == 2)
        cameras++;
    return cameras;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    printf("%d\n", minCameraCover(root));

    return 0;
}