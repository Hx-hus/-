#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int N = 100010, M = N * 2;
int n;
int h[N], e[M], ne[M], idx;//������
int ans = N;//��
bool tf[N];//bool����Ѿ��ҹ��ĵ�
int a, b;

//������ͷ��
void add(int a, int b)
{
	e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

int dfs(int u)
{
	tf[u] = true;//�߹��Ĵ��ϱ��
	int size = 0, num = 0;
	for (int i = h[u]; i != -1; i = ne[i])//����������
	{
		int j = e[i];//��ʾ��ͨ�Ľڵ�
		if (tf[j])continue;//������㱻�������ˣ���continue����ȥ������һ���ڵ�
		int s = dfs(j);//�ҵ�����ӽڵ��һƬ�Ľڵ���
		size = max(size, s);//�ҵ�����ӽڵ�������ӽڵ�����һ���ڵ��
		num += s;//���㵱ǰu�����нڵ�
	}
	size = max(size, n - num - 1);//size����������ֵ
	ans = min(size, ans);//�õ���С�����ֵ
	return num + 1;
}
int main()
{
	cin >> n;

	memset(h, -1, sizeof h);
	int i = n - 1;
	while (i--)
	{
		cin >> a >> b;
		add(a, b); add(b, a);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}