#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>
using namespace std;

const int N = 100010;

int val[N], l[N], r[N], idx;
//插入
void push(int k, int x)
{
	val[idx] = x;//先创建一个新的节点
	r[idx] = r[k];//让新节点的指向右边的指针指向右边
	l[idx] = k;//让新节点指向左边的数指向左边
	l[r[k]] = idx;//让新节点左边的数指向新节点
	r[k] = idx++;//让新节点右边的数指向新节点，然后插入一个数之后，计数++
}
//删除
void remove(int k)
{
	l[r[k]] = l[k];
	r[l[k]] = r[k];
}

int main()
{
	r[0] = 1, l[1] = 0,idx=2;
	int m;
	cin >> m;
	while (m--)
	{
		int k, x;
		string c;
		cin >> c;
		if (c == "L")
		{
			cin >> x;
			push(0, x);
		}
		else if (c == "R")
		{
			cin >> x;
			push(l[1], x);
		}
		else if (c == "D")
		{
			cin >> k;
			remove(k + 1);
		}
		else if (c == "IL")
		{
			cin >> k >> x;
			push(l[k + 1], x);
		}
		else
		{
			cin >> k >> x;
			push(k + 1, x);
		}
	}
	for (int i = r[0]; i != 1; i = r[i])cout << val[i] << " ";
	cout << endl;
	return 0;
}