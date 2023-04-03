#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1010, MOD = 100000007;
int f[N][N];
int n, s, a, b;

int get_mod(int n, int m)
{
	return (n % m + m) % m;
}
int main()
{
	scanf("%d%d%d%d", &n, &s, &a, &b);

	f[0][0] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n; j++)
			f[i][j] = (f[i - 1][get_mod(j - (n - i) * a, n)] + f[i - 1][get_mod(j + (n - i) * b, n)]) % MOD;
	printf("%d\n", f[n - 1][get_mod(s, n)]);
	return 0;
}