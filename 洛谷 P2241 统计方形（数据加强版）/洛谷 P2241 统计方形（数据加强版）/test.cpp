#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

ll n, m, count1, count2;
int main()
{
	cin >> n >> m;
	for (ll i = 1; i <= min(n, m); i++)
		count1 += (n - i + 1) * (m - i + 1);//正方形的个数
	count2 = n * (n + 1) * m * (m + 1) / 4 - count1;//长方形的个数，也就是整个矩形的全部总和
	cout << count1 << " " << count2 << endl;
	return 0;
}