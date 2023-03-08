#define _CRT_SECURE_NO_WARNINGS 1 

#include"slist.h"

// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//申请一个新节点
SListNode* BuySLiltNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	if (*pplist== NULL)
	{
		*pplist = newnode;
	}
	//找尾
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next->next!= NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
		
	}
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);

	SListNode* f = *pplist;
	(*pplist)->next = f->next;
	free(f);
	f = NULL;
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur=cur->next;
	}
	return NULL;
}
//pos后面插入
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//pos后面删除
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	assert(pos->next);
	SListNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}
// 单链表的销毁
void SListDestroy(SListNode* plist)
{
	assert(plist);
	free(plist);
	plist = NULL;
}