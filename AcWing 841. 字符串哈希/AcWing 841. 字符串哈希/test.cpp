#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ULL;
const int N = 100010, P = 131;
char op[N];
int n, m;
ULL _hash[N], p[N];//_hash是用于存放哈希值的，p是用于处理字符串的p进制

ULL get(int l, int r)
{
	return _hash[r] - _hash[l - 1] * p[r - l + 1];//将区间内的哈希值返回去
}
int main()
{
	cin >> n >> m >> op + 1;
	p[0] = 1;//因为字符串从1开始，所以要初始化一下0，防止l和r有0
	for (int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] * P;//p进制的处理
		_hash[i] = _hash[i - 1] * P + op[i];//将哈希值处理好
	}
	while (m--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (get(l1, r1) == get(l2, r2))cout << "Yes" << endl;                                                                                                                                                
		else cout << "No" << endl;
	}
	return 0;
}
