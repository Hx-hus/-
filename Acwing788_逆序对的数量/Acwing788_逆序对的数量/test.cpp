#define _CRT_SECURE_NO_WARNINGS 1 
#include<iostream>
using namespace std;

const int N = 100010;
int n;
int arr[N];
int tmp[N];
long long  m_sort(int arr[], int l, int r)
{
	if (l >= r)return 0;
	int mid = l + r >> 1;
	long long _count = m_sort(arr, l, mid) + m_sort(arr, mid + 1, r);
	int t = 0;
	int i = l;
	int j = mid + 1;
	while (i <= mid && j <= r)
		if (arr[i] <= arr[j])tmp[t++] = arr[i++];
		else
		{
			_count += mid - i + 1;
			tmp[t++] = arr[j++];
		}
	while (i <= mid)tmp[t++] = arr[i++];
	while (j <= r)tmp[t++] = arr[j++];
	for (j = 0, i = l; i <= r; i++, j++)arr[i] = tmp[j];
	return _count;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << m_sort(arr, 0, n - 1) << endl;
	return 0;
}