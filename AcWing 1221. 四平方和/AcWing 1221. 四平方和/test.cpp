#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 2500010;
int n, m;

struct sum
{
	int s, c, d;
	bool operator<(const sum& t)const
	{
		if (s != t.s) return s < t.s;
		if (c != t.c) return c < t.c;
		return d < t.d;
	}
}sum[N];

int main()
{
	scanf("%d", &n);

	for (int i = 0; i * i <= n; i++)
		for (int j = i; i * i + j * j <= n; j++)
			sum[m++] = { i * i + j * j, i, j };

	sort(sum, sum + m);//保证数组有序，能使用二分

	for (int i = 0; i * i <= n; i++)
		for (int j = 0; i * i + j * j <= n; j++)
		{
			int t = n - i * i - j * j;
			int l = 0, r = m;
			while (l < r)
			{
				int mid = (l + r) >> 1;
				if (sum[mid].s >= t) r = mid;
				else l = mid + 1;
			}
			if (sum[r].s == t)
			{
				printf("%d %d %d %d\n", i, j, sum[r].c, sum[r].d);
				return 0;
			}

		}
	return 0;
}