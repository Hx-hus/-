#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 6;
int n;
char g[N][N], b[N][N];
int dx[5] = { 0, 0, 0, -1, 1 }, dy[5] = { -1, 0, 1, 0, 0 };

void turn(int x, int y)
{
	for (int i = 0; i < 5; i++)
	{
		int a = x + dx[i], b = y + dy[i];
		if (a < 0 || a >= 5 || b < 0 || b >= 5) continue;
		g[a][b] ^= 1;
	}
}

int main()
{
	scanf("%d", &n);

	while (n--)
	{
		for (int i = 0; i < 5; i++) scanf("%s", g[i]);
		int res = 10;
		for (int i = 0; i <= 31; i++)
		{
			memcpy(b, g, sizeof g);
			int s = 0;
			for (int k = 0; k < 5; k++)
			{
				if (i >> k & 1)
				{
					s++;
					turn(0, k);
				}
			}//对第一行进行操作
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 5; j++)
				{
					if (g[i][j] == '0')
					{
						s++;
						turn(i + 1, j);
					}
				}
			bool st = false;
			for (int i = 0; i < 5; i++)
			{
				if (g[4][i] == '0')
				{
					st = true;
					break;
				}
			}
			if (!st) res = min(res, s);
			memcpy(g, b, sizeof g);
		}
		if (res <= 6)printf("%d\n", res);
		else printf("-1\n");
	}
	return 0;
}