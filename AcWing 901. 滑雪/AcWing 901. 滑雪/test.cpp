#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 310;
int g[N][N];
int f[N][N];
int n, m;
int dx[4] =  {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; //Æ«ÒÆÁ¿

int dp(int i, int j)
{
	int& k = f[i][j];
	if (k != -1) return k;

	k = 1;
	for (int i = 0; i < 4; i++)
	{
		int a = i + dx[i], b = j + dy[i];
		if (a >= 1 && a <= n && b >= 1 && b <= m && g[i][j] > g[a][b])
			k = max(k, dp(a, b) + 1);
	}
	return k;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &g[i][j]);
	memset(f, -1, sizeof f);

	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			res = max(f[i][j], dp(i, j));
	printf("%d\n", res);
	return 0;
}