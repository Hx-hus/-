#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;
const int N = 1010;
int arr[N][N];
int pre[N][N];
int n;
int m;
int q;

int main() 
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + arr[i][j];
	while (q--)
	{
		int a, b, a1, b1;
		cin >> a >> b >> a1 >> b1;
		cout << pre[a1][b1] - pre[a1][b- 1] - pre[a - 1][b1] + pre[a - 1][b - 1] << endl;
	}
	return 0;
}
