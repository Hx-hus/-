#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };
 
bool isUnivalTree(struct TreeNode* root)
{
    if (!root)
    {
        return true;
    }
    if (root->left)
    {
        if (root->val != root->left->val || !isUnivalTree(root->left))
            return false;
    }
    if (root->right)
    {
        if (root->val != root->right->val || !isUnivalTree(root->right))
            return false;
    }
    return true;
}