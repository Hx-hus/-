#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
int a[N];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a+n);
	for (int i = 0; i < n; i++)cout << a[i] << " ";
	cout << endl;
	return 0;
}