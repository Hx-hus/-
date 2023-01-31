#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <cstring>
using namespace std;

char s[14];
char c;
int h = 0;
int k = 0;
int main()
{
	cin >> s;
	for (int i = 0; i < 11; i++)
	{
		if (s[i] != '-')//不等于-的时候进来，然后进行加乘操作
		{
			k++;
			h += k * (s[i] - '0');//用ASCII码将字符换成数字
		}
	}
	h %= 11;//取模11，得到最后的数
	if (h == 10)
	{
		c = 'X';//如果是10的时候赋值X
	}
	else
	{
		c = h + '0';//将h变成字符赋值给c

	}
	if (c == s[12])
	{
		cout << "Right" << endl;
	}
	else
	{
		s[12] = c;
		cout << s;
	}
	return 0;
}