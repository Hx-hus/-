#define _CRT_SECURE_NO_WARNINGS 1 


 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

 };
 
class Solution {
public:

    int sumOfLeftLeaves(TreeNode* root)
    {
        static int count = 0;
        if (root == nullptr) return 0;
        TreeNode* newroot = new TreeNode();
        newroot = root->left;
        if (newroot && !newroot->left && !newroot->right)
        {
            count += newroot->val;
            sumOfLeftLeaves(root->right);
        }
        else
        {
            sumOfLeftLeaves(root->left);
            sumOfLeftLeaves(root->right);
        }
        return count;
    }
};