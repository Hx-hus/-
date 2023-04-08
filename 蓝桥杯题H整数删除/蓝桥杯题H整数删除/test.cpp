#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 50010, M = 1e8 + 10;
int arr[N], tmps[N];
int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	memcpy(tmps, arr, sizeof arr);
	sort(tmps + 1, tmps + n + 1);
	int c = k;
	for (int i = 1; i < n && c; i++)
	{
		memcpy(tmps, arr, sizeof arr);
		sort(tmps + 1, tmps + n + 1);
		int a = tmps[1];
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == a)
			{
				arr[j] = arr[j + 1] + a;
				arr[j - 1] += a;
				for (int v = j + 1; v < n; v++) 
					arr[v] = arr[v + 1];
				break;
			}
		}
		c--;
	}
	for (int i = 1; i <= n - k; i++) printf("%d ", arr[i]);
	return 0;
}
