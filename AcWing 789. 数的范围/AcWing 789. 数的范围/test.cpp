#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int sum[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &sum[i]);
	while (m--)
	{
		int x;
		scanf("%d", &x);
		int l = 0, r = n - 1;
		while (l < r)
		{
			int mid = (l + r ) >> 1;
			if (sum[mid] >= x) r = mid;
			else l = mid + 1;
		}
		int c = r;
		l = c, r = n - 1;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (sum[mid] <= x) l = mid;
			else r = mid - 1;
		}
		int d = r;
		if (sum[c] == x) printf("%d %d\n", c, d);
		else printf("-1 -1\n");
	}

	return 0;
}
