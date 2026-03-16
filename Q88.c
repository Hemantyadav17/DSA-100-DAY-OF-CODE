// Given the root of a binary tree, return the preorder traversal of its nodes' values.


#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void preorder(struct TreeNode* root){
    if(root==NULL) return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main(){

    struct TreeNode* root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(3);

    preorder(root);

    return 0;
}