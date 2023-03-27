#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1010;
int n, m;
char a[N], b[N];
int f[N][N];

int main()
{
	scanf("%d%s", &n, a + 1);
	scanf("%d%s", &m, b + 1);

	for (int i = 0; i <= m; i++) f[0][i] = i;//初始化a从0开始的操作次数
	for (int i = 0; i <= n; i++) f[i][0] = i;//初始化b从0开始的操作次数

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
		}
	printf("%d\n", f[n][m]);
	return 0;
}