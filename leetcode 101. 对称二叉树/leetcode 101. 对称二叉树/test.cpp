#define _CRT_SECURE_NO_WARNINGS 1 

struct TreeNode 
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool cheak(struct TreeNode* l, struct TreeNode* r)
{
    if (!l && !r) return true;
    if (!l || !r) return false;
    if (l->val == r->val) return cheak(l->left, r->right) && cheak(l->right, r->left);
    else return false;

}

bool isSymmetric(struct TreeNode* root)
{
    return cheak(root, root);
}