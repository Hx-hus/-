#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
using namespace std;

int n;

struct stu
{
	int a, id, c, math, e;
}a[310];

int cmp(stu a, stu b)
{
	if (a.a != b.a) return a.a > b.a;//比较总分
	if (a.c != b.c) return a.c > b.c;//比较语文
	return a.id < b.id;		
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].c >> a[i].math >> a[i].e;
		a[i].a = a[i].c + a[i].math + a[i].e;//计算成绩总分
		a[i].id = i + 1;
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < 5; i++)
		cout << a[i].id << " " << a[i].a << endl;
	return 0;
}