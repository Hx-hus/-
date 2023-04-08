#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int k;
string s;
char c1, c2;

int main()
{
	cin >> k;
	cin >> s >> c1 >> c2;

	int res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int count = 0;
		if (s[i] == c1)
		{
			for (int j = i; j < s.size(); j++)
			{
				count++;
				if (s[j] == c2)
				{
					if (count >= k) res++;
					else continue;
				}
			}
		}
	}
	printf("%d\n", res);
	return 0;
}
