#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;//单链表
int d[N];//标记距离
int a, b;
queue<int> q;

//单链表头插
void add(int a,int b)
{
	e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

int bfs()
{
	memset(d, -1, sizeof d);
	d[1] = 0;//先将第一层打上标记
	q.push(1);//第一层入队，开始找第二层
	while(q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1)//说明没有被找过
			{
				d[j] = d[t] + 1;
				q. push(j);

			}
		}
	}
	return d[n];
}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m--)
	{
		cin >> a >> b;
		add(a, b);
	}
	cout << bfs() << endl;
	return 0;
}

