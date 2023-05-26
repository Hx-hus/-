#define _CRT_SECURE_NO_WARNINGS 1 

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

bool isson(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (!root && !subRoot) return true;
    if (!root || !subRoot) return false;
    if (root->val == subRoot->val)
        if (isson(root->left, subRoot->left) && isson(root->right, subRoot->right))
            return true;
    return false;
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (!root) return false;
    if (root->val == subRoot->val)
    {
        if (isson(root, subRoot))
            return true;
    }
    if (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot))
        return true;
    return false;
}