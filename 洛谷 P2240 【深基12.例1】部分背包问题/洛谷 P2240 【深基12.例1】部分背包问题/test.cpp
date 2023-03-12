#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct A
{
	int m, v;//重量和价值
}a[110];

int n, t, c;
float ans;

bool cmp(A x, A y)
{
	return x.v / x.m > y.v / x.m;//判断单价谁多
}
int main()
{
	cin >> n >> t;//背包剩余容量
	for (int i = 0; i < n; i++)cin >> a[i].m >> a[i].v;
	sort(a, a + n, cmp);//对单价进行排序
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i].m > t)break;//如果背包不能完整装下金币就跳出
		t -= a[i].m;
		ans += a[i].v;
	}
	if (i < n)
	{
		ans += 1.0 * t / a[i].m * a[i].v;//剩余空间能装下的金币
	}
	printf("%.2lf", ans);
	return 0;
}