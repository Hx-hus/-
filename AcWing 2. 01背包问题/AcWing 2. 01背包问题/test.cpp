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
		for (int j = m; j >= arts[i].v; j--)//j��m��ʼ����Ϊ������Ҫ��ȥĿǰ��Ӧ�����������Ҫ���ڻ��ߵ����������Ų��ᷢ��Խ��
			f[j] = max(f[j - arts[i].v] + arts[i].w, f[j]);
	printf("%d", f[m]);
	return 0;
}