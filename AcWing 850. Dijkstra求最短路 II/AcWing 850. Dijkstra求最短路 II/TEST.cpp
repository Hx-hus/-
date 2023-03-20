#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;
int h[N], e[N], ne[N], w[N], idx;
int dijk[N];
int n,m;
bool st[N];
int a, b, c;

//单链表插入
void add(int a, int b, int c)
{
	e[idx] = b; ne[idx] = h[a]; w[idx] = c; h[a] = idx++;
}

int dijkstar()
{
	memset(dijk, 0x3f, sizeof dijk);
	dijk[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;//小根堆
	heap.push({ 0, 1 });//前面放点到起点的距离，后面点的编号
	while (heap.size())//当队列为空的时候就证明找完了
	{
		auto t = heap.top();
		heap.pop();
		int val = t.second;

		if (st[val]) continue;//如果这个点已经录入是最短路
		st[val] = true;//如果这个点没有被打上标记，现在就打上标记

		for (int i = h[val]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dijk[j] > dijk[val] + w[i])//如果当这个点的最短路大于
			{
				dijk[j] = dijk[val] + w[i];
				heap.push({ dijk[j],j });//更新到堆当中
			}
		}
	}
	if (dijk[n] == 0x3f3f3f3f)return -1;
	return dijk[n];

}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);

	while (m--)
	{
		cin >> a >> b >> c;
		add(a, b, c);
	}

	cout << dijkstra() << endl;
	return 0;
}
