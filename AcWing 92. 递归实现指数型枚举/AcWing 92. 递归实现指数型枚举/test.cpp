#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 16;

int n;
int f[N];

void dfs(int u)
{
	if (u > n)
	{
		for (int i = 1; i <= n; i++)
			if (f[i] == 1) printf("%d ", i);
		puts("");
		return;
	}

	f[u] = 2;//不选
	dfs(u + 1);
	f[u] = 0;//恢复现场
	
	f[u] = 1;//选
	dfs(u + 1);
	f[u] = 0;//恢复现场
}

int main()
{
	scanf("%d", &n);

	dfs(1);
	return 0;
}
