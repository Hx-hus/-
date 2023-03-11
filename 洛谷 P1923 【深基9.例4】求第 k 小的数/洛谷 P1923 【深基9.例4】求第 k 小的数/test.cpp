#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 500010;
int a[N];
int n, k;


int main()
{
	cin >> n>> k;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a,a+n);
	cout << a[k];
	return 0;
}