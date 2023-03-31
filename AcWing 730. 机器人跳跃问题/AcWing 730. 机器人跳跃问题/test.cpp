#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;
int g[N];
int n;
int m;

bool cheak(int x)
{
	for (int i = 0; i < n; i++)
	{
		x = 2 * x - g[i];
		if (x >= m) return true;
		if (x < 0) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &g[i]);
		m = max(m, g[i]);
	}
	int l = 0, r = m;
	while (l < r)
	{
		int mid = (l + r)>> 1;
		if (cheak(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", r);
	return 0;
}