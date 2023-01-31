#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
using namespace std;

int n[3];
char a, b, c;
int main()
{
	cin >> n[0] >> n[1] >> n[2];
	cin >> a >> b >> c;
	sort(n, n + 3);//ÅÅÐòº¯Êý
	cout << n[a - 'A'] << " " << n[b - 'A'] << " " << n[c - 'A'];
	return 0;
}