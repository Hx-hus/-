#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

const int N = 15;

struct fly
{
	int t, d, l, k;
	
}v[N];

bool cmp(const struct fly& a, const struct fly& b)
{
	if (a.k <= b.k) return true;
	else if (a.t <= b.t) return true;
	else if (a.d <= b.d) return true;
	else return a.l <= b.l;
}
int n, m;
int t_min = 1e9, t_max;

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> m;
		for (int i = 1; i <= m; i++)
		{
			cin >> v[i].t >> v[i].d >> v[i].l;
			v[i].k = v[i].t + v[i].d;
		}
		bool st = false;
		sort(v + 1, v + m + 1,cmp);
		v[1].k -= v[1].d;
		for (int i = 1; i < m; i++)
		{
			if (v[i].k + v[i].l > v[i + 1].k)
			{
				st = true;
				break;
			}
		}
		if (st) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}