#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long ll;

const int N = 10010;
int a[N], b[N], c[N];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	sort(a + 1, a + n + 1);
	sort(c + 1, c + n + 1);
	int l, r, t1, t2;
	ll res = 0;
	for (int i = 1; i <= n; i++)
	{
		l = 1, r = n;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (a[mid] < b[i]) l = mid;
			else r = mid - 1;
		}
		t1 = l;
		if (a[l] >= b[i]) t1--;
		l = 1, r = n;
		while (l < r)
		{
			int mid = (l + r ) >> 1;
			if (c[mid] > b[i]) r = mid;
			else l = mid + 1;
		}
		t2 = n - l + 1;
		if (c[l] <= b[i]) t2--;
		res += (ll)t1 * t2;
	}
	printf("%d\n", res);
	return 0;
}

