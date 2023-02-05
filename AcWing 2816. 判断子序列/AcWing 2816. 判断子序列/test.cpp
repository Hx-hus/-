#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

typedef long long ll;

const int N = 100010;
ll a[N], b[N];
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	int i, j;
	for (i = 0, j = 0; j < m; j++)
		if (i < n && b[j] == a[i])
			i++;
	if (i == n)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}