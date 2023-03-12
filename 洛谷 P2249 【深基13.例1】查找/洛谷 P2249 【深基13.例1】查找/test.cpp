#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 100010;
int a[N], m, n, q;

int find(int x)
{
	int l = 1, r = n;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (a[mid] == x)return mid;
		else if (a[mid] > x)r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= m; i++) {
		cin >> q;
		cout << find(q) << " ";
	}
	return 0;
}