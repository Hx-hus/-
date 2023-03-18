#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int N = 100010, M = N * 2;
int n;
int h[N], e[M], ne[M], idx;//单链表
int ans = N;//答案
bool tf[N];//bool标记已经找过的点
int a, b;

//单链表头插
void add(int a, int b)
{
	e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

int dfs(int u)
{
	tf[u] = true;//走过的打上标记
	int size = 0, num = 0;
	for (int i = h[u]; i != -1; i = ne[i])//遍历单链表
	{
		int j = e[i];//表示连通的节点
		if (tf[j])continue;//当这个点被遍历过了，就continue跳上去遍历下一个节点
		int s = dfs(j);//找到这个子节点的一片的节点数
		size = max(size, s);//找到这个子节点和其他子节点中哪一个节点多
		num += s;//计算当前u的所有节点
	}
	size = max(size, n - num - 1);//size是子树最大的值
	ans = min(size, ans);//得到最小的最大值
	return num + 1;
}
int main()
{
	cin >> n;

	memset(h, -1, sizeof h);
	int i = n - 1;
	while (i--)
	{
		cin >> a >> b;
		add(a, b); add(b, a);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}