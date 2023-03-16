#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstring>
using namespace std;

const int N = 200003, null = 0x3f3f3f3f;
int _hash[N], n, x;

int find(int x)
{
	int k = (x % N + N) % N;//x为负数的时候，在c++取模也是负数，为了让取模结果变成正数，加上一个n，则一定为正，在取模一个n，加的这个n就消掉了
	while (_hash[k] != null && _hash[k] != x)//当这个位置里面有数据的时候并且这个数据和x不相等发的时候，就找下一个位置
	{
		k++;
		if (k == N)k = 0;//当k找到头就从头开始找
	}
	return k;
}
int main()
{
	cin >> n;
	memset(_hash, 0x3f, sizeof _hash);
	while (n--)
	{
		string op;
		cin >> op >> x;
		if (op[0] == 'I')_hash[find(x)] = x;//插入
		else
		{
			if (_hash[find(x)] != null) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}