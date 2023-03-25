#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 110;

int f[N][N];
int v[N], w[N], s[N];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d%d", &v[i], &w[i], &s[i]);
	
	for (int i = 1; i <= n; i++)//
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
				f[i][j] = max(f[i - 1][j - v[i] * k] + w[i] * k, f[i][j]);
	printf("%d\n", f[n][m]);
	return 0;
}