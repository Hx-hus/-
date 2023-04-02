#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;//可能会爆int，所以这里使用ll

const int N = 100010;
int n, k;
ll s[N], cnt[N];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &s[i]);
		s[i] += s[i - 1];//处理出前缀和
	}
	
	ll res = 0;
	cnt[0] = 1;//余数为0的区间肯定是
	for (int i = 1; i <= n; i++)
	{
		res += cnt[s[i] % k];//有两个以上余数一样的就说明是k的倍数
		cnt[s[i] % k]++;
	}
	printf("%lld\n", res);
	return 0;
}