#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 10;

int n;
int f[N];
bool st[N];//用于判重

void dfs(int u)
{
	if (u > n)
	{
		for (int i = 1; i <= n; i++)printf("%d ", f[i]);
		puts("");
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!st[i])
		{
			f[u] = i;
			st[i] = true;
			dfs(u + 1);

			//恢复现场
			f[u] = 0;
			st[i] = false;
		}
	}
}
int main()
{
	scanf("%d", &n);
	
	dfs(1);

	return 0;
}
