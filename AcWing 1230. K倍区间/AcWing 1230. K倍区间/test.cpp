#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;//���ܻᱬint����������ʹ��ll

const int N = 100010;
int n, k;
ll s[N], cnt[N];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &s[i]);
		s[i] += s[i - 1];//�����ǰ׺��
	}
	
	ll res = 0;
	cnt[0] = 1;//����Ϊ0������϶���
	for (int i = 1; i <= n; i++)
	{
		res += cnt[s[i] % k];//��������������һ���ľ�˵����k�ı���
		cnt[s[i] % k]++;
	}
	printf("%lld\n", res);
	return 0;
}