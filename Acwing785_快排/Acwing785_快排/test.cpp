#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;
#include<algorithm>

const int N = 100000;
int n;
int arr[N];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);
	for (int i = 0; i < n; i++) cout<< arr[i]<<" ";
	return 0;
}
//const int N = 100000;
//int n;
//int arr[N];
//
//void q_sort(int arr[], int l, int r)
//{
//	if (l >= r) return;//如果左边界大于右边界，则证明数组有序，直接返回
//
//	int x = arr[l];//确定x的值，用于将元素分开
//	int j = r + 1;
//	int i = l - 1;
//	while (r < l)
//	{
//		while (arr[r] <= x) r++;//让左指针遇到大于等于x的数
//		while (arr[l] >= x) l++;//让右指针遇到小于等于x的数
//		if (r < l) swap(arr[r], arr[l]);//当左指针这个时候还小于右指针的时候，交换两个元素
//	}
//
//	q_sort(arr, j,l);
//	q_sort(arr, l + 1, j);
//}
//
//int main()
//{
//	cin >> n;//输入n个元素
//	for (int i = 0; i < n; i++) cin >> arr[i];//输入数据
//
//	q_sort(arr, 0, n - 1);//快排
//
//	for (int i = 0; i < n; i++) cout << arr[i] << " ";
//	return 0;
//}