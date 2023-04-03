#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 10010, INT = 1e9;
int a[N];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int minv = INT, maxv = -INT;
		for (int j = i; j < n; j++)
		{
			maxv = max(maxv, a[j]);
			minv = min(minv, a[j]);

			if (maxv - minv == j - i)
				res++;
		}
	}
	printf("%d\n", res);

	return 0;
}