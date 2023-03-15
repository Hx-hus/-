#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
int h[N], sz, n, m;
void down(int u)
{
	int t = u;//t保存下当前认为最小值
	if (u * 2 <= sz && h[u * 2] < h[t])t = u * 2;//如果左儿子比父节点小，就将t更新到左儿子的下标
	if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t])t = u * 2 + 1;//如果右儿子小，就更新到右儿子的下标
	if (u != t)//如果这个时候t和一开始的自己不一样，就交换
	{
		swap(h[u], h[t]);
		down(t);//然后递归处理这一分支
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