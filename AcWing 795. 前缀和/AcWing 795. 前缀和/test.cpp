#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 100010;
int n;
int m;
int r;
int l;
int arr[N];
int pre1 = 0;
int pre2 = 0;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	while (m--)
	{
		pre1 = 0;
		pre2 = 0;
		cin >> l >> r;
		for (int i = 0; i < r; i++)
		{
			if (i < l - 1)
			{
				pre1 += arr[i];
			}
			pre2 += arr[i];
		}
		cout<<pre2 - pre1<<endl;
	}
	return 0;
}