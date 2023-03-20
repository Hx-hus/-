#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 510;

int g[N][N];//稠密图用邻接矩阵来存
int dijk[N];//1到所有点的距离
int n, m;
bool st[N];//求出一个点到起点的最短路的时候，就将这个变成ture
int a, b, c;

int dijkstar()
{
	memset(dijk, 0x3f, sizeof dijk);//先全部初始化成无穷
	dijk[1] = 0;//起点到起点距离为0

	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || dijk[t] > dijk[j]))t = j;//找到不在s中的距离最近的点

		for (int j = 1; j <= n; j++)
			dijk[j] = min(dijk[j], dijk[t] + g[t][j]);//用t更新周围点的距离

		st[t] = true;//表示t这个已经找到最短路了
	}

	if (dijk[n] == 0x3f3f3f3f)return -1;
	return dijk[n];
}
int main()
{
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);//将g内的先全部初始化成无穷大
	while (m--) 
	{
		cin >> a >> b >> c;
		g[a][b] = min(c, g[a][b]);//因为可能存在重边，我们只需要最小的那一条就行
	}

	int t = dijkstar();
	cout << t << endl;

	return 0;
}
