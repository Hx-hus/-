#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

int a[210], b[210];
int n, x, y;
int a_b[5][5] = { {0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0} };

int main()
{
	cin >> n >> x >> y;
	int count_a = 0, count_b = 0;
	for (int i = 0; i < x; i++)cin >> a[i];
	for (int i = 0; i < y; i++)cin >> b[i];
	for (int i = x; i <n; i++)a[i] = a[i - x];//将a出的循环全部写入数组
	for (int i = y; i <n; i++)b[i] = b[i - y];//同上
	for (int i = 0; i < n; i++)
	{
		count_a += a_b[a[i]][b[i]];//通过得分表来计算得分
		count_b += a_b[b[i]][a[i]];
	}
	cout << count_a << " " << count_b;
	return 0;
}