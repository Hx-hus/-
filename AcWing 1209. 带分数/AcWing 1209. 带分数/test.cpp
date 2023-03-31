#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;
const int N = 10;

int n;
bool st[N], s[N];
int ans;

bool cheak(int a, int c)
{
	ll b = (ll)c * n - c * a;
	if (!a || !b || !c) return false;

	memcpy(s, st, sizeof st);
	while (b)
	{
		int x = b % 10;
		b /= 10;
		if (!x || s[x]) return false;
		s[x] = true;
	}
	for (int i = 1; i <= 9; i++)
		if (!s[i])
			return false;
	return true;
}
void dfs_c(int u, int a, int c)
{
	if (u > 9) return;//当u大于9的时候，说明b已经没有位置了，这个方案就不合理
	if (cheak(a, c)) ans++;//当确定a和c之后有唯一的b，判断一下这组是否符合，符合就将答案加1
	for (int i = 1; i <= 9; i++)
	{
		if (!st[i])
		{
			st[i] = true;
			dfs_c(u + 1, a, c * 10 + i);//与a同理
			st[i] = false;
		}
	}

}
void dfs_a(int u, int a)
{
	if (a >= n) return;
	if (a) dfs_c(u, a, 0);//当a不是0的时候，递归找是否有匹配的c和b

	for (int i = 1; i <= 9; i++)
	{
		if (!st[i])
		{
			st[i] = true;
			dfs_a(u + 1, a * 10 + i);//进入下一层，a要在第二位上加i，所以要先乘十
			st[i] = false;//恢复现场
		}
	}
}


int main()
{
	scanf("%d", &n);

	dfs_a(0, 0);

	printf("%d\n", ans);

	return 0;
}
