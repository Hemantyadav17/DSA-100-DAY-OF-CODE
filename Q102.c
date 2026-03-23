//Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T
// that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 #include <stdio.h>
#include <stdlib.h>

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

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->val == key)
        return root;

    if (key < root->val)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    int n;
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int p_val, q_val;
    scanf("%d %d", &p_val, &q_val);

    struct TreeNode* p = search(root, p_val);
    struct TreeNode* q = search(root, q_val);

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        printf("%d\n", lca->val);

    return 0;
}