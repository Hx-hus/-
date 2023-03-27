#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1010;
int n, m;
char n1[N], m1[N];
int f[N][N];

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s%s", n1 + 1, m1 + 1);

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = max(f[i][j - 1], f[i - 1][j]);
			if (n1[i] == m1[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
		}
	printf("%d\n", f[n][m]);
	return 0;
}