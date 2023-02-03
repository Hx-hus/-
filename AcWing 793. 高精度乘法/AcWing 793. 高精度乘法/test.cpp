#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;
#include<vector>
#include<string>

vector<int> mul(vector<int>& A, int& B)
{
	vector<int> C;
	if (B == 0)
	{
		C.push_back(0);
		return C;
	}
	int t = 0;
	for (int i = 0; i < A.size() || t; i++)
	{
		if (i < A.size())t += A[i] * B;
		C.push_back(t % 10);
		t /= 10;
	}
	return C;
}
int main()
{
	string a;
	vector<int> A;
	int B;
	cin >> a >> B;
	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
	vector<int> C;
	C = mul(A, B);
	for (int i = C.size() - 1; i >= 0; i--)cout << C[i];
	return 0;
}