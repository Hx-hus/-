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
//	if (l >= r) return;//�����߽�����ұ߽磬��֤����������ֱ�ӷ���
//
//	int x = arr[l];//ȷ��x��ֵ�����ڽ�Ԫ�طֿ�
//	int j = r + 1;
//	int i = l - 1;
//	while (r < l)
//	{
//		while (arr[r] <= x) r++;//����ָ���������ڵ���x����
//		while (arr[l] >= x) l++;//����ָ������С�ڵ���x����
//		if (r < l) swap(arr[r], arr[l]);//����ָ�����ʱ��С����ָ���ʱ�򣬽�������Ԫ��
//	}
//
//	q_sort(arr, j,l);
//	q_sort(arr, l + 1, j);
//}
//
//int main()
//{
//	cin >> n;//����n��Ԫ��
//	for (int i = 0; i < n; i++) cin >> arr[i];//��������
//
//	q_sort(arr, 0, n - 1);//����
//
//	for (int i = 0; i < n; i++) cout << arr[i] << " ";
//	return 0;
//}