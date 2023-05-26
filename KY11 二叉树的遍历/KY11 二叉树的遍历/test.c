#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;


BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#') //判断是否越界或者到达叶子结点
	{
		(*pi)++;
		return NULL;
	}

	BTNode* node = (BTNode*)malloc(sizeof(BTNode));

	node->_data = a[*pi];
	(*pi)++;

	node->_left = BinaryTreeCreate(a, pi);
	node->_right = BinaryTreeCreate(a, pi);

	return node;
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (!root) return;

	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);

}


int main()
{
	char str[105];
	int a = 0;
	scanf("%s", str);
	BTNode* s = (BTNode*)malloc(sizeof str);
	BinaryTreeCreate(str, &a);
	BinaryTreeInOrder(s);
	return 0;
}