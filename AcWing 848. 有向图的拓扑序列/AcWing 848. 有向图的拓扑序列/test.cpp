#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1000010;
int h[N], e[N], ne[N], idx;
int n, m, a, b;
int d[N];//入度
int q[N];
int hh, tt = -1;

//单链表插入
void add(int a, int b)
{
	e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

bool topsort()
{
	for (int i = 1; i <= n; i++)
		if (!d[i])
			q[++tt] = i;
	while (hh <= tt)
	{
		int t = q[hh++];//获取到头并且弹出头
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (--d[j] == 0)q[++tt] = j;//当这个点减减的入度为0的时候，就添加进来
		}
	}
	return tt == n - 1;
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m--)
	{
		cin >> a >> b;
		add(a, b);
		d[b]++;
	}
	if (!topsort())cout << -1 << endl;
	else
	{
		for (int i = 0; i < n; i++)cout << q[i] << " ";
		cout << endl;

	}
	return 0;
}

