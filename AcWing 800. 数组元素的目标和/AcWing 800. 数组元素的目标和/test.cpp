#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;
typedef long long  ll;

const int N = 100010;
ll a[N], b[N];
int n, m, x;

int main()
{
	cin >> n >> m >> x;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	for (int i = 0, j = m - 1; i < n; i++)
	{
		while (j >= 0 && a[i] + b[j] > x)j--;
		//��Ϊ���������飬����������������������x��ʱ��j--,����ǲ����ھ�--,��С�ڵ�ʱ��ֻ��Խ��ԽС
		if (a[i] + b[j] == x)
		{
			cout << i << " " << j << endl;
			break;
		}
	}
	return 0;
}