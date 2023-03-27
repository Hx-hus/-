#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 15, M = 1010;
char str[M][N];
int f[N][N];
int n, m;

int dp(char str[], char s[])
{
	int la = strlen(str + 1), lb = strlen(s + 1);
	for (int i = 0; i <= lb; i++) f[0][i] = i;//初始化a从0开始的操作次数
	for (int i = 0; i <= la; i++) f[i][0] = i;//初始化b从0开始的操作次数

	for (int i = 1; i <= la; i++)
		for (int j = 1; j <= lb; j++)
		{
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			if (str[i] == s[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
		}
	return f[la][lb];
}
int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) scanf("%s", str[i] + 1);
	
	while (m--)
	{
		char s[N];
		int im;
		scanf("%s%d", s + 1, &im);
		int res = 0;
		for (int i = 0; i < n; i++)
			if (dp(str[i], s) <= im) res++;
		printf("%d\n", res);
	}

	return 0;
}