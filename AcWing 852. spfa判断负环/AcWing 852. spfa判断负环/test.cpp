#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N],cut[N];
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b; ne[idx] = h[a]; w[idx] = c; h[a] = idx++;
}
bool spfa()
{
	queue <int> q;
	for (int i = 1; i <= n; i++)
	{
		st[i] = true;
		q.push(i);
	}

	while (q.size())
	{
		int t = q.front();
		q.pop();

		st[t] = false;
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cut[i] += 1;
				if (cut[i] >= n)return true;
				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return false;
}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}


	if (spfa())cout << "Yes"<< endl;
	else cout << "No" << endl;

	return 0;
}