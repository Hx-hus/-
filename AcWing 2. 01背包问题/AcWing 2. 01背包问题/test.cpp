#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1010;

struct art
{
	int v, w;
}arts[N];

int n, m;
int f[N];

int main()
{
	scanf("%d%d", &n,&m);
	for(int i = 0; i < n; i ++)
	{
		int v, w;
		scanf("%d%d", &v, &w);
		arts[i] = { v,w };
	}
	for (int i = 0; i < n; i++)
		for (int j = m; j >= arts[i].v; j--)//j从m开始是因为，下面要减去目前对应的体积，必须要大于或者等于这个体积才不会发生越界
			f[j] = max(f[j - arts[i].v] + arts[i].w, f[j]);
	printf("%d", f[m]);
	return 0;
}