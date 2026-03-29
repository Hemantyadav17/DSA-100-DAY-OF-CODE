//given the root of a binary tree, flatten the tree into a "linked list":
 //The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list
 // and the left child pointer is always null. The "linked list" should be in the same order as a pre-order traversal of the binary tree.

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

// Build tree
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

// Flatten function
void flatten(Node* root) {
    if (root == NULL) return;

    flatten(root->left);
    flatten(root->right);

    Node* temp = root->right;

    root->right = root->left;
    root->left = NULL;

    Node* curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }

    curr->right = temp;
}

// Print flattened list
void printList(Node* root) {
    while (root != NULL) {
        printf("%d ", root->val);
        root = root->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    flatten(root);

    printList(root);

    return 0;
}