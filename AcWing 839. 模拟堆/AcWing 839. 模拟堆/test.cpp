#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int N = 100010;
int h[N], ph[N], hp[N], sz, n, m;//ph是存的这个数是第几个插入到树的，hp是映射在ph的，即ph[k]=j,hp[j]=k

void h_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}
//下沉
void down(int u)
{
	int t = u;//t保存下当前认为最小值
	if (u * 2 <= sz && h[u * 2] < h[t])t = u * 2;//如果左儿子比父节点小，就将t更新到左儿子的下标
	if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t])t = u * 2 + 1;//如果右儿子小，就更新到右儿子的下标
	if (u != t)//如果这个时候t和一开始的自己不一样，就交换
	{
		h_swap(u, t);
		down(t);//然后递归处理这一分支
	}
}
//上升
void up(int u)
{
	while (u / 2 && h[u / 2] > h[u])//当子节点大于父节点的时候，就进入进行交换
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
			hp[sz] = m;//将第几个插入映射到映射数组当中
			h[sz] = x;
			up(sz);//因为在最下面，只需要up
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
			k = ph[k];//找到第k个数的下标
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


