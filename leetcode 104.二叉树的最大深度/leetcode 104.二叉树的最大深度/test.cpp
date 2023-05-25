#define _CRT_SECURE_NO_WARNINGS 1 

#include<algorithm>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
 
int maxDepth(struct TreeNode* root)
{
    if (!root) return 0;
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}