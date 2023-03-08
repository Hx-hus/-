#define _CRT_SECURE_NO_WARNINGS 1 

#include"slist.h"

// �������ӡ
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
//����һ���½ڵ�
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
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	if (*pplist== NULL)
	{
		*pplist = newnode;
	}
	//��β
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
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}
// �������βɾ
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
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);

	SListNode* f = *pplist;
	(*pplist)->next = f->next;
	free(f);
	f = NULL;
}
// ���������
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
//pos�������
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//pos����ɾ��
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	assert(pos->next);
	SListNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}
// �����������
void SListDestroy(SListNode* plist)
{
	assert(plist);
	free(plist);
	plist = NULL;
}