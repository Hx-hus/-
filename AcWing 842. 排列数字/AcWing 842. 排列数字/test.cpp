#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 10;
int n;
int a[N];
bool tf[N];

void dfs(int u)
{
	if (u == n)
	{
		for (int i = 0; i < n; i++)cout << a[i] << " ";
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!tf[i])//��û�б�ǵ�ʱ�򣬾�֤�������û�б�ʹ�ù�
		{
			a[u] = i;
			tf[i] = true;//��ʹ�ù��ĵ���ϱ��
			dfs(u + 1);//�ݹ��ҵ���һ����
			tf[i] = false;//�ָ��ֳ�
		}
	}
}
int main()
{
	cin >> n;

	dfs(0);

	return 0;
}