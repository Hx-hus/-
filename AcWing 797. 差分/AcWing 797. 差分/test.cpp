#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 100010;
int arr[N];
int b[N];
int n, m;

void insert(int l, int r, int c)
{
	b[l] += c;
	b[r + 1] -= c;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	for (int i = 1; i <= n; i++)insert(i, i, arr[i]);

	while (m--)
	{
		int l, r, c;
		cin >> l >> r >> c;
		insert(l, r, c);
	}
	for (int i = 1; i <= n; i++)b[i] += b[i - 1];
	for (int i = 1; i <= n; i++)cout << b[i] << " ";
	return 0;
}