#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 110;
char s[N], d[N];
int ans;

void over(int i)
{
	if (s[i] == 'o') s[i] = '*';
	else s[i] = 'o';
}
int main()
{
	scanf("%s%s", s, d);
	int sl = strlen(s);
	for (int i = 0; i < sl; i++)
		if (s[i] != d[i])
		{
			over(i);
			over(i + 1);
			ans++;
		}
	printf("%d\n", ans);
	return 0;
}