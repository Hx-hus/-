#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int N = 100010;
int h[N], ph[N], hp[N], sz, n, m;//ph�Ǵ��������ǵڼ������뵽���ģ�hp��ӳ����ph�ģ���ph[k]=j,hp[j]=k

void h_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}
//�³�
void down(int u)
{
	int t = u;//t�����µ�ǰ��Ϊ��Сֵ
	if (u * 2 <= sz && h[u * 2] < h[t])t = u * 2;//�������ӱȸ��ڵ�С���ͽ�t���µ�����ӵ��±�
	if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t])t = u * 2 + 1;//����Ҷ���С���͸��µ��Ҷ��ӵ��±�
	if (u != t)//������ʱ��t��һ��ʼ���Լ���һ�����ͽ���
	{
		h_swap(u, t);
		down(t);//Ȼ��ݹ鴦����һ��֧
	}
}
//����
void up(int u)
{
	while (u / 2 && h[u / 2] > h[u])//���ӽڵ���ڸ��ڵ��ʱ�򣬾ͽ�����н���
	{
		h_swap(u, u / 2);
		u /= 2;
	}
}

int main()
{
	cin >> n;
	while (n--)
	{
		string op;
		cin >> op;
		int x, k;
		if (op == "I")
		{
			cin >> x;
			ph[++m] = ++sz;
			hp[sz] = m;//���ڼ�������ӳ�䵽ӳ�����鵱��
			h[sz] = x;
			up(sz);//��Ϊ�������棬ֻ��Ҫup
		}
		else if (op == "PM")cout << h[1] << endl;
		else if (op == "DM")
		{
			h_swap(1, sz);
			sz--;
			down(1);
		}
		else if (op == "D")
		{
			cin >> k;
			k = ph[k];//�ҵ���k�������±�
			h_swap(k, sz);
			sz--;
			down(k);
			up(k);
		}
		else 
		{
			cin >> k >> x;
			k = ph[k];
			h[k] = x;
			down(k);
			up(k);
		}
	}
	return 0;
}


