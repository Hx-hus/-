#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main()
{
	double n;
	cin >> n;
	double l = -1e4, r = 1e4;
	while (r - l > 1e-8)
	{
		double mid = (l + r) / 2;
		if (mid * mid * mid >= n) r = mid;
		else l = mid;
	}
	printf("%6lf", r);
	return 0;
}