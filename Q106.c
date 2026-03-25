//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    struct TreeNode* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct TreeNode* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        printf("[]\n");
        return;
    }

    struct TreeNode* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = queue[front++];
            printf("%d ", curr->val);

            if (curr->left)
                queue[rear++] = curr->left;

            if (curr->right)
                queue[rear++] = curr->right;
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("[]\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}