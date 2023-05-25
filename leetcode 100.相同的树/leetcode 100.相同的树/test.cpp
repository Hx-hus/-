#define _CRT_SECURE_NO_WARNINGS 1 


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (!p && !q) return true;
    else if (!p || !q) return false;
    else if (p->val != q->val) return false;
    else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}