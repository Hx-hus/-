#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;
char p[N], s[M];
int n, m, ne[N];
int main()
{
	cin >> n >> p + 1 >> m >> s + 1;
	//找next数组
	for (int i = 2, j = 0; i <= n; i++)//i从1开始时，匹配失败的时候，就退到0，next[0]不用计算，因为我们从一开始存的，
	{
		while (j && p[i] != p[j + 1])j = ne[j];//当j还没退到0或者当下标i和j+1不相等的时候，就找上一个最长后缀，直到相等为止
		if (p[i] == p[j + 1])j++;//匹配成功，后缀进一位
		ne[i] = j;//将后缀长度更新到next数组当中
	}
	//kmp匹配过程
	for (int i = 1, j = 0; i <= m; i++) 
	{
		while (j && s[i] != p[j + 1])j = ne[j];//与找next数组当中的思路基本一致，当匹配失败的时候，就用小一点的后缀去和s串匹配
		if (s[i] == p[j + 1])j++;//匹配成功，后缀进一位
		if (j == n)//当j和n相等的时候，说明匹配结束了，找到了
		{
			cout << i - n << " ";
			j = ne[j];//匹配完成时，想下一个匹配的时候，要向后退，最好是退到上一个后缀上面
		}
	}
	return 0;
}