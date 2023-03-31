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
	if (u > 9) return;//��u����9��ʱ��˵��b�Ѿ�û��λ���ˣ���������Ͳ�����
	if (cheak(a, c)) ans++;//��ȷ��a��c֮����Ψһ��b���ж�һ�������Ƿ���ϣ����Ͼͽ��𰸼�1
	for (int i = 1; i <= 9; i++)
	{
		if (!st[i])
		{
			st[i] = true;
			dfs_c(u + 1, a, c * 10 + i);//��aͬ��
			st[i] = false;
		}
	}

}
void dfs_a(int u, int a)
{
	if (a >= n) return;
	if (a) dfs_c(u, a, 0);//��a����0��ʱ�򣬵ݹ����Ƿ���ƥ���c��b

	for (int i = 1; i <= 9; i++)
	{
		if (!st[i])
		{
			st[i] = true;
			dfs_a(u + 1, a * 10 + i);//������һ�㣬aҪ�ڵڶ�λ�ϼ�i������Ҫ�ȳ�ʮ
			st[i] = false;//�ָ��ֳ�
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
