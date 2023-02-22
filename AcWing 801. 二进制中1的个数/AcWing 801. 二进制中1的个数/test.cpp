#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

int n;

//得到数中最后一位1
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
		while (x)//当x减成0的跳出循环
		{
			x -= lowbit(x);//每次都减去自身二进制位中的最后一位1
			s++;//减去一位1的同时s++
		}
		cout << s << " ";
	}
	return 0;
}