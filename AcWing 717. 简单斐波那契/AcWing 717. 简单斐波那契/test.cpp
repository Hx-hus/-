#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>

using namespace std;

int a, b, c, n;

void f()
{
	if (n == 1)
	{
		printf("%d\n", a);
		return;
	}
	if (n == 2)
	{
		printf("%d ", a);
		printf("%d\n", b);
		return;
	}
	printf("%d ", a);
	printf("%d ", b);
	for (int i = 3; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
		printf("%d ", c);
	}

}
int main()
{
	scanf("%d", &n);
	a = 0, b = 1;
	f();
	return 0;
}