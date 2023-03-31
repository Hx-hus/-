#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 30;
int n, m;
int way[N];

void dfs(int u, int s)
{
	if (n + u - s < m) return;
	if (u > m)
	{
		for (int i = 1; i <= m; i++) printf("%d ", way[i]);
		puts("");
		return;
	}
	for (int i = s; i <= n; i++)
	{
		way[u] = i;
		dfs(u + 1, i + 1);
		way[u] = 0;
	}
}
int main()
{
	scanf("%d%d", &n, &m);

	dfs(1, 1);

	return 0;
}