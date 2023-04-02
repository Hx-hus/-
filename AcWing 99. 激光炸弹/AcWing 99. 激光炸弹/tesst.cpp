#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 5010;
int n, m;
int k, v;
int s[N][N];

int main()
{
	scanf("%d%d", &k, &v);
	v = min(5001, v);

	n = m = v;
	while (k--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		x++, y++;//Ϊ���ø��ü���ǰ׺�ͣ����±��1��ʼ
		n = max(n, x), m = max(m, y);//�ó�x��y������ģ���ö�ٳ����½�	
		s[x][y] += w;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];//Ԥ�����ǰ׺��
	int res = 0;
	for (int i = v; i <= n; i++)
		for (int j = v; j <= m; j++)
			res = max(res, s[i][j] - s[i - v][j] - s[i][j - v] + s[i - v][j - v]);
	printf("%d\n", res);

	return 0;
}
