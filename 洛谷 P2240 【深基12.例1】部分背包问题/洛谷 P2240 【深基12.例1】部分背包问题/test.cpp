#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct A
{
	int m, v;//�����ͼ�ֵ
}a[110];

int n, t, c;
float ans;

bool cmp(A x, A y)
{
	return x.v / x.m > y.v / x.m;//�жϵ���˭��
}
int main()
{
	cin >> n >> t;//����ʣ������
	for (int i = 0; i < n; i++)cin >> a[i].m >> a[i].v;
	sort(a, a + n, cmp);//�Ե��۽�������
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i].m > t)break;//���������������װ�½�Ҿ�����
		t -= a[i].m;
		ans += a[i].v;
	}
	if (i < n)
	{
		ans += 1.0 * t / a[i].m * a[i].v;//ʣ��ռ���װ�µĽ��
	}
	printf("%.2lf", ans);
	return 0;
}