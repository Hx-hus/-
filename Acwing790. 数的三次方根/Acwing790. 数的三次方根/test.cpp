#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

double n;
double l = -10000;
double r = 10000;
double mid;
int main()
{
	cin >> n;
	while (r - l >= 1e-8)//保证精度在六位
	{
		mid = (l + r) / 2;
		if (mid * mid * mid <= n) r = mid;
		else l = mid;
	}
	printf("%.6lf", l);
	return 0;
}

//int main()
//{
//	cin >> n;
//	cout << cbrt(n) << endl;
//	return 0;
//}
