#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 20;
char chess[N][N];
bool col[N], dg[N], udg[N];//�ж�ÿһ�к������Խ����Ƿ��лʺ����
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
		if (!col[i] && !dg[u + i] && !udg[n - i + u])//�ж�ÿһ�к�ÿһ�������Խ����Ƿ������Ӵ���
		{
			chess[u][i] = 'Q';
			col[i] = dg[u + i] = udg[n - u + i] = true;//��ÿһ�к�ÿһ�������Խ��߱����
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