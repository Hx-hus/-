#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 510, M = 10010;

struct edge
{
	int a,b,c;
}edges[M];

int n, m, k;
int dist[N];
int last[N];//备份数组，始终比dist少一个点
int a, b, c;

void bellman_ford()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for (int i = 0; i < k; i++)
	{
		memcpy(last, dist, sizeof dist);//备份操作，如果不备份可能发生串联
		for (int j = 0; j < m; j++)
		{
			int a = edges[j].a, b = edges[j].b, w = edges[j].c;
			dist[b] = min(dist[b], last[a] + w);
		}
	}
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m;i++)
	{
		cin >> a >> b >> c;
		edges[i] = { a,b,c };
	}

	bellman_ford();

	if (dist[n] > 0x3f3f3f3f / 2)cout << "impossible" << endl;
	else cout << dist[n] << endl;
	return 0;
}