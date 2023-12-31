#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>

vector<int> div(vector<int>& A, int& b,int &r)
{
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		r = (r * 10 + A[i]);
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0)C.pop_back();
	return C;
}
int main()
{
	string a;
	int b;
	vector<int> A;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
	vector<int> C;
	int r;
	C = div(A, b, r);
	for (int i = C.size() - 1; i >= 0; i--)cout << C[i];
	cout << r;
	return 0;
}