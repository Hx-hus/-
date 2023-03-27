#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 310;
int s[N];
int f[N][N];
int n; 

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) scanf("%d", &s[i]);

	for (int i = 1; i <= n; i++) s[i] += s[i - 1];//Ç°×ººÍ
	
	for (int i = 2; i <= n; i++)
		for (int j = 1; j + i - 1 <= n; j++)
		{
			int l = j, r = j + i - 1;
			f[l][r] = 1e8;
			for (int k = l; k < r; k++) f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
		}
	printf("%d\n", f[1][n]);

	return 0;
}