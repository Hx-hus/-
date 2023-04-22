#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>

using namespace std;

struct List
{
	int val;
	List* next;
};
//初始化
void init(List*& l)
{
	l = new List();
	l->next = l;
}
//创建链表
void makelist(List*& l, List*& r, int a[], int n)
{
	r = l;
	l->val = a[0];
	for (int i = 0; i < n; i++)
	{
		List* nlist = new List;
		nlist->val = a[i];
		r->next = nlist;
		r = nlist;
	}
	r->next = l;
}
//约瑟夫问题
void Josephproblem(List*& l, List*& pre, int count, int move)
{
	int i = 1;
	while (--move)
	{
		l = l->next;
		pre = pre->next;
	}
	while (l->next != l)
	{
		if (i == count)
		{
			i = 1;
			pre->next = l->next;
			delete l;
			l = pre->next;
		}
		else
		{
			pre = pre->next;
			l = l->next;
			i++;
		}
	}
	cout << l->val << endl;
}

int main()
{
	List* head;
	init(head);
	List* rear;
	int n, m;
	cin >> n >> m;
	int* a = new int[n];
	for (int i = 0; i < n; i++)a[i] = i + 1;
	makelist(head, rear, a, n);
	Josephproblem(head, rear, m, 1);
	delete head;

	return 0;
}