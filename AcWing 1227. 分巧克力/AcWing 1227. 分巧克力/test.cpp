#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;
int h[N], w[N];
int n, k;

bool cheak(int m)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res += (h[i] / m) * (w[i] / m);
		if (res >= k) return true;
	}
	return false;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d%d", &h[i], &w[i]);

	int l = 0, r = 1e5;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (cheak(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", r);
	return 0;
}