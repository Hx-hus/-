#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

typedef long long ll;

const int N = 12, M = 1 << N;
int n, m;
ll f[N][M];
vector<int> sta[M];
bool st[M];

int main()
{
	while (cin >> n >> m, n || m)
	{
		for (int i = 0; i < 1 << n; i++)
		{
			int cnt = 0;
			bool is_v = true;
			for (int j = 0; j < n; j++)
				if (i >> j & 1)//如果这里为1,则证明这里前面一个延伸出来一个方块
				{
					if (cnt & 1)//判断一下cnt目前是不是1，如果是1，就证明这个不能放
					{
						is_v = false;
						break;
					}
					cnt = 0;
				}
				else cnt++;
			if (cnt & 1) is_v = false;
			st[i] = is_v;
		}
		for (int i = 0; i < 1 << n; i++)
		{
			sta[i].clear();
			for (int j = 0; j < 1 << n; j++)
				if ((i & j) == 0 && st[i | j]) sta[i].push_back(j);
		}
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for (int i = 1; i <= m; i++)
			for (int j = 0; j < 1 << n; j++)
				for (auto z : sta[j])
					f[i][j] += f[i - 1][z];
		cout << f[m][0] << endl;
	}
	
	return 0;
}