#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1400, INT = 1e9;

int n, m, k;
int d[N][N];

void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) d[i][j] = 0;
			else d[i][j] = INT;
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int c;
			cin >> c;
			d[i][j] = min(d[i][j], c);
		}
	floyd();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << d[i][j] << "|" << " ";
		}
		cout << endl;
	}


	return 0;
}