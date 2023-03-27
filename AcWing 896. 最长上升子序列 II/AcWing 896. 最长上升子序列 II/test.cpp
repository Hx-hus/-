#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 100010;
int a[N];
int f[N];
int n;

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	int len = 0;
	for (int i = 0; i < n; i++)
	{
		int l = 0, r = len;
		while (l < r)
		{
			int mid = (l + r + 1) / 2;
			if (f[mid] < a[i]) l = mid;
			else r = mid - 1;
		}
		len = max(len, r + 1);
		f[r + 1] = a[i];
	}
	printf("%d\n", len);
	return 0;
}