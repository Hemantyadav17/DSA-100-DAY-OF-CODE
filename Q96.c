//Given the root of a binary tree, return the sum of all left leaves. 
//A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

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

int sumOfLeftLeaves(struct TreeNode* root){
    if(root == NULL) return 0;

    int sum = 0;

    if(root->left){
        if(root->left->left == NULL && root->left->right == NULL)
            sum += root->left->val;
        else
            sum += sumOfLeftLeaves(root->left);
    }

    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main(){

    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("%d", sumOfLeftLeaves(root));

    return 0;
}