#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 100010;
int a[N], b[N];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	int _max = 0;
	for (int i = 0, j = 0; i < n; i++)
	{
		b[a[i]]++;//�����ظ�Ԫ�ص�ʱ�򣬻���ͬһ��λ��++
		while (b[a[i]] > 1)//����1��ʱ��˵�������ظ���
		{
			b[a[j]]--;//��jԪ�ض�Ӧ��λ�ý���--
			j++;//����һ��û���ظ����ֵ�����
		}
		_max = max(_max, i - j + 1);
	}
	cout << _max << endl;
	return 0;
}