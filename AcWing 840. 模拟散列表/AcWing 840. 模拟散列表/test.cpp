#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstring>
using namespace std;

const int N = 200003, null = 0x3f3f3f3f;
int _hash[N], n, x;

int find(int x)
{
	int k = (x % N + N) % N;//xΪ������ʱ����c++ȡģҲ�Ǹ�����Ϊ����ȡģ����������������һ��n����һ��Ϊ������ȡģһ��n���ӵ����n��������
	while (_hash[k] != null && _hash[k] != x)//�����λ�����������ݵ�ʱ����������ݺ�x����ȷ���ʱ�򣬾�����һ��λ��
	{
		k++;
		if (k == N)k = 0;//��k�ҵ�ͷ�ʹ�ͷ��ʼ��
	}
	return k;
}
int main()
{
	cin >> n;
	memset(_hash, 0x3f, sizeof _hash);
	while (n--)
	{
		string op;
		cin >> op >> x;
		if (op[0] == 'I')_hash[find(x)] = x;//����
		else
		{
			if (_hash[find(x)] != null) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}