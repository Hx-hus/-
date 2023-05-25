#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdlib.h>


struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
const int N = 110;


void BinaryTreePrevOrder(struct TreeNode* root, int* res, int* sub)
{
	if (!root) return;
	res[(*sub)++] = root->val;
	BinaryTreePrevOrder(root->left, res, sub);
	BinaryTreePrevOrder(root->right, res, sub);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * N);
	*returnSize = 0;
	BinaryTreePrevOrder(root, res, returnSize);
	return res;
}