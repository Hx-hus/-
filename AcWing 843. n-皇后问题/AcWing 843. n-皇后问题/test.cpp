#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 20;
char chess[N][N];
bool col[N], dg[N], udg[N];//判断每一行和正反对角线是否有皇后出现
int n;

void dfs(int u)
{
	if (u == n)
	{
		for (int i = 0; i < n; i++)cout << chess[i] << endl;
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i++)
		if (!col[i] && !dg[u + i] && !udg[n - i + u])//判断每一行和每一个正反对角线是否有棋子存在
		{
			chess[u][i] = 'Q';
			col[i] = dg[u + i] = udg[n - u + i] = true;//将每一行和每一个正反对角线标记上
			dfs(u + 1);
			col[i] = dg[u + i] = udg[n - u + i] = false;
			chess[u][i] = '.';
		}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			chess[i][j] = '.';

	dfs(0);

	return 0;
}