#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

#define fo(x,i,j) for(int x=i;x<=j;x++)
int n, count, ans;

int main()
{
	cin >> n;
	fo(a, 1, 3) fo(b, 1, 3) fo(c,1, 3) fo(d, 1, 3)fo(e, 1, 3)
		fo(f, 1, 3)fo(g, 1, 3) fo(h, 1, 3)fo(i, 1, 3) fo(j, 1, 3)
				if (a + b + c + d + e + f + g + h + i + j == n)
						ans++;
	cout << ans << endl;
	fo(a, 1, 3) fo(b, 1, 3) fo(c, 1, 3) fo(d, 1, 3)fo(e, 1, 3)
		fo(f, 1, 3)fo(g, 1, 3) fo(h, 1, 3)fo(i, 1, 3) fo(j, 1, 3)
		if (a + b + c + d + e + f + g + h + i + j == n)
			cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << endl;
	return 0;
}