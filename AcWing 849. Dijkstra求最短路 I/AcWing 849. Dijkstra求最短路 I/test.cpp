#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 510;

int g[N][N];//����ͼ���ڽӾ�������
int dijk[N];//1�����е�ľ���
int n, m;
bool st[N];//���һ���㵽�������·��ʱ�򣬾ͽ�������ture
int a, b, c;

int dijkstar()
{
	memset(dijk, 0x3f, sizeof dijk);//��ȫ����ʼ��������
	dijk[1] = 0;//��㵽������Ϊ0

	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || dijk[t] > dijk[j]))t = j;//�ҵ�����s�еľ�������ĵ�

		for (int j = 1; j <= n; j++)
			dijk[j] = min(dijk[j], dijk[t] + g[t][j]);//��t������Χ��ľ���

		st[t] = true;//��ʾt����Ѿ��ҵ����·��
	}

	if (dijk[n] == 0x3f3f3f3f)return -1;
	return dijk[n];
}
int main()
{
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);//��g�ڵ���ȫ����ʼ���������
	while (m--) 
	{
		cin >> a >> b >> c;
		g[a][b] = min(c, g[a][b]);//��Ϊ���ܴ����رߣ�����ֻ��Ҫ��С����һ������
	}

	int t = dijkstar();
	cout << t << endl;

	return 0;
}
