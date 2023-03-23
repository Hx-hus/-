#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100010, M = 200010, INT = 0x3f3f3f3f; 
int n, m;
int p[N];

struct edge
{
	int a, b, c;

	bool operator< (const edge & W)const//重载一下比较操作符
	{
		return c < W.c;
	}
}edges[M];


int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
int kruskal()
{
	sort(edges, edges + m);//将数据按照权重排好

	for (int i = 1; i <= n; i++) p[i] = i;//将并查集初始化

	int res = 0, cut = 0;

	for (int i = 0; i < m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].c;

		a = find(a);
		b = find(b);
		if (a != b)
		{
			p[a] = b;
			res += w;
			cut++;
		}
	}
	if (cut < n - 1) return INT;
	return res;
}
int main()
{
	cin >> n >> m;
	for(int i= 0;i<m;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[i] = { a,b,c };
	}

	int t = kruskal();

	if (t == INT)cout << "impossible" << endl;
	else cout << t << endl;
	return 0;
}