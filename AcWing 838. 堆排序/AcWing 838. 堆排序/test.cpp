#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
int h[N], sz, n, m;
void down(int u)
{
	int t = u;//t�����µ�ǰ��Ϊ��Сֵ
	if (u * 2 <= sz && h[u * 2] < h[t])t = u * 2;//�������ӱȸ��ڵ�С���ͽ�t���µ�����ӵ��±�
	if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t])t = u * 2 + 1;//����Ҷ���С���͸��µ��Ҷ��ӵ��±�
	if (u != t)//������ʱ��t��һ��ʼ���Լ���һ�����ͽ���
	{
		swap(h[u], h[t]);
		down(t);//Ȼ��ݹ鴦����һ��֧
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> h[i], sz++;
	for (int i = n / 2; i; i--)down(i);
	while (m--)
	{
		cout << h[1] << " ";
		h[1] = h[sz--];
		down(1);
	}
	return 0;
}