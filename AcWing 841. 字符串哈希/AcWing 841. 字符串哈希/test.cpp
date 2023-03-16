#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ULL;
const int N = 100010, P = 131;
char op[N];
int n, m;
ULL _hash[N], p[N];//_hash�����ڴ�Ź�ϣֵ�ģ�p�����ڴ����ַ�����p����

ULL get(int l, int r)
{
	return _hash[r] - _hash[l - 1] * p[r - l + 1];//�������ڵĹ�ϣֵ����ȥ
}
int main()
{
	cin >> n >> m >> op + 1;
	p[0] = 1;//��Ϊ�ַ�����1��ʼ������Ҫ��ʼ��һ��0����ֹl��r��0
	for (int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] * P;//p���ƵĴ���
		_hash[i] = _hash[i - 1] * P + op[i];//����ϣֵ�����
	}
	while (m--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (get(l1, r1) == get(l2, r2))cout << "Yes" << endl;                                                                                                                                                
		else cout << "No" << endl;
	}
	return 0;
}
