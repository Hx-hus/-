#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1010;
int v[N], w[N];
int f[N];
int n, m;

//���������Ż�

int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);

	for (int i = 1; i <= n; i++)
		for (int j = v[i]; j <= m; j++) //j��v[i]��ʼ��Ȼ�ᵼ������Խ��
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	printf("%d\n", f[m]);
 	return 0;
}
//����������������ʹ��
//int main()
//{
//	scanf("%d%d", &n, &m);
//
//	for (int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);
//
//
//	for (int i = 1; i <= n; i++)
//		for (int j = v[i]; j <= m; j++)//j��v[i]��ʼ��Ȼ�ᵼ������Խ��
//			for (int k = 0; k <= j / v[i]; k++)//��i����Ʒ������ȡj/v[i]������k������Ϊj/v[i]��
//				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
//	printf("%d\n", f[n][m]);
//
//	return 0;
//}
