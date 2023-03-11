#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

struct pre
{
	string a;
	int num;
}a[25];

int n;

bool cmp(pre a, pre b)
{
	if (a.a.size() != b.a.size())return a.a.size() > b.a.size();
	return a.a > b.a;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].a;
		a[i].num = i + 1;
	}
	sort(a,  a+ n, cmp);
	cout << a[0].num << endl << a[0].a << endl;
	return 0;
}
