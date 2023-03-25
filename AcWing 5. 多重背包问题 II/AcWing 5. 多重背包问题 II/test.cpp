#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstring>
#include<algorithm>

using namespace std;

const int N = 12010, M = 2010;
int f[M];
int v[N], w[N];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);

	int cut = 0;
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int k = 1;
		if (k <= c)
		{
			cut++;
			v[cut] = a * k;
			w[cut] = b * k;
			c -= k;
			k *= 2;//用二的次方来把就把背包分成01背包问题
		}
		if (c > 0)
		{
			cut++;
			v[cut] = a * c;
			w[cut] = b * c;
		}


	}

	n = cut;
	//01背包优化使用
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= v[i]; j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	printf("%d\n", f[m]);
	return 0;
}