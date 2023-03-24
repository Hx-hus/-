#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1010;
int v[N], w[N];
int f[N];
int n, m;

//滚动数组优化

int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);

	for (int i = 1; i <= n; i++)
		for (int j = v[i]; j <= m; j++) //j从v[i]开始不然会导致数组越界
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	printf("%d\n", f[m]);
 	return 0;
}
//暴力做法，不建议使用
//int main()
//{
//	scanf("%d%d", &n, &m);
//
//	for (int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);
//
//
//	for (int i = 1; i <= n; i++)
//		for (int j = v[i]; j <= m; j++)//j从v[i]开始不然会导致数组越界
//			for (int k = 0; k <= j / v[i]; k++)//第i个物品最多可以取j/v[i]个，则k的上限为j/v[i]个
//				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
//	printf("%d\n", f[n][m]);
//
//	return 0;
//}
