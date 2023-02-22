#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 100010;
int head, val[N], ne[N], idx;

//��ʼ������
void init()
{
	head = -1;
	idx = 0;
}
//ͷ������
void add_head(int x)
{
	val[idx] = x;
	ne[idx] = head;
	head = idx++;
}
//����
void add(int k, int x)
{
	val[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx++;
}
//ɾ��
void remove(int k)
{
	ne[k] = ne[ne[k]];
}
int main()
{
	int m;
	cin >> m;
	init();
	while (m--)
	{
		int x, k;
		char c;
		cin >> c;
		if (c == 'H')
		{
			cin >> x;
			add_head(x);
		}
		else if (c == 'D')
		{
			cin >> k;
			if (!k)head = ne[head];
			else remove(k - 1);//���ǵĽڵ��Ǵ�0��ʼ�ģ������k����Ҳ���ǲ����±�k-1��λ��
		}
		else
		{
			cin >> k >> x;
			add(k - 1, x);
		}
	}
	for (int i = head; i != -1; i = ne[i])cout << val[i] << " ";
	cout << endl;
	return 0;
}