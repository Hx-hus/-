#define _CRT_SECURE_NO_WARNINGS 1 

#define x first
#define y second

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

const int N = 5;
char f[N][N], s[N][N];
vector<pii> d;

int get(int x, int y)
{
	return x * 4 + y;
}
void turn_one(int x, int y)
{
	if (f[x][y] == '-') f[x][y] = '+';
	else f[x][y] = '-';
}
void turn_all(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		turn_one(x, i);
		turn_one(i, y);
	}
	turn_one(x, y);//因为上面那样会让要按下去的按钮变化两次，相当于没有变化，就在变一次
}
int main()
{
	for (int i = 0; i < 4; i++) scanf("%s", f[i]);
	for (int op = 1; op <= 1 << 16; op++)
	{
		vector<pii> tmp;
		memcpy(s, f, sizeof f);
		for(int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (op >> get(i, j) & 1)
				{
					tmp.push_back({ i, j });
					turn_all(i, j);//将因为点亮这个按钮而影响其他按钮的按钮更新
				}
		bool b = false;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (f[i][j] == '+')
					b = true;
		if (!b)
		{
			if (d.empty() || d.size() > tmp.size())//当存放答案的容易为空或者当这个方案要按下的大于新的方案，就更新
				d = tmp;
		}
		memcpy(f, s, sizeof f);
	}
	printf("%d\n", d.size());
	for (auto i : d) printf("%d %d\n", i.x + 1, i.y + 1);
	return 0;
}