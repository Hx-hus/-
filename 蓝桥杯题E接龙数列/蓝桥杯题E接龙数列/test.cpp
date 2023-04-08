#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 10010;

int n;
int num[N];
int f[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
	for (int i = 1; i <= n; i++)
	{
		f[i] = 1;
		for (int j = 1; j < i; j++)
		{
			int a = num[j] % 10;
			int b = num[i];
			while (b > 9)
			{
				b /= 10;
			}
			if (a == b)
				f[i] = max(f[i], f[j] + 1);
			f[i] = max(f[i], f[j]);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res, f[i]);
	printf("%d", n - res);
	return 0;
}