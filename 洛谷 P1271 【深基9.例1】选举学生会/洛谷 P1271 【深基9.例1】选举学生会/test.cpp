#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;
int a[1010];
int n, m, tmp;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        a[tmp]++;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < a[i]; j++)
            cout << i << " ";
    cout << endl;
    return 0;
}