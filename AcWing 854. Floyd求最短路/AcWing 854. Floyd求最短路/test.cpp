#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 210, INT = 1e9;

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
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}

	floyd();

	while (k--)
	{
		int a, b;
		cin >> a >> b;

		int t = d[a][b];
		if (t >= INT/2)cout << "impossible" << endl;
		else cout << t << endl;
	}

	return 0;
}