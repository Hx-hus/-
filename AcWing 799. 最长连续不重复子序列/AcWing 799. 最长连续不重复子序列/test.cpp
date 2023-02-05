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
		b[a[i]]++;//当有重复元素的时候，会在同一个位置++
		while (b[a[i]] > 1)//大于1的时候说明了有重复的
		{
			b[a[j]]--;//将j元素对应的位置进行--
			j++;//找下一个没有重复数字的数列
		}
		_max = max(_max, i - j + 1);
	}
	cout << _max << endl;
	return 0;
}