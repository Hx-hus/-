#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 100010;
int n;
int q;
int arr[N];

int main()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++)cin >> arr[i];
	int l = 0;
	int r = n - 1;
	int i = l;
	int j = r;
	int x = 0;
	while (q--)
	{
		cin >> x;
		i = l;
		j = r;
		while (i < j)
		{
			int mid = (i + j)/2;
			if (arr[mid]<x)i = mid+1;
			else j = mid;
		}
		if (arr[i] != x)
		{
			cout << "-1 -1" << endl;
			continue;
		}
		int i1 = 0;
		int j1 = n-1;
		while (i1+1 < j1)
		{
			int mid = (i1 + j1+1)/2;
			if (arr[mid]<=x)
				i1 = mid;
			else j1 = mid-1;
		}
		if (arr[i1] == x)
		{
			cout << i << " " << j1 << endl;
		}
	}
	return 0;
}