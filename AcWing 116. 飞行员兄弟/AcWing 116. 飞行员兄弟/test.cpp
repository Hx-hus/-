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
	turn_one(x, y);//��Ϊ������������Ҫ����ȥ�İ�ť�仯���Σ��൱��û�б仯�����ڱ�һ��
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
					turn_all(i, j);//����Ϊ���������ť��Ӱ��������ť�İ�ť����
				}
		bool b = false;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (f[i][j] == '+')
					b = true;
		if (!b)
		{
			if (d.empty() || d.size() > tmp.size())//����Ŵ𰸵�����Ϊ�ջ��ߵ��������Ҫ���µĴ����µķ������͸���
				d = tmp;
		}
		memcpy(f, s, sizeof f);
	}
	printf("%d\n", d.size());
	for (auto i : d) printf("%d %d\n", i.x + 1, i.y + 1);
	return 0;
}