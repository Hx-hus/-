#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100000;
int arr[N];
int k;
int n;

int main()
{
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	cout << arr[k-1];
	return 0;
}