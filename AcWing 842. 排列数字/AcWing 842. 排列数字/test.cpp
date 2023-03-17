#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 10;
int n;
int a[N];
bool tf[N];

void dfs(int u)
{
	if (u == n)
	{
		for (int i = 0; i < n; i++)cout << a[i] << " ";
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!tf[i])//当没有标记的时候，就证明这个数没有被使用过
		{
			a[u] = i;
			tf[i] = true;//将使用过的点打上标记
			dfs(u + 1);//递归找到下一个点
			tf[i] = false;//恢复现场
		}
	}
}
int main()
{
	cin >> n;

	dfs(0);

	return 0;
}