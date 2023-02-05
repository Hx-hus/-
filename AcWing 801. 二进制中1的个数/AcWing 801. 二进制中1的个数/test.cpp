#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

int n;

int lowbit(int a)
{
	return a & (-a);
}
int main()
{
	cin >> n;
	int s = 0;
	int x = 0;
	while (n--)
	{	
		cin >> x;
		s = 0;
		while (x)
		{
			x -= lowbit(x);
			s++;
		}
		cout << s << " ";
	}
	return 0;
}