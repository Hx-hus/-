#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>
using namespace std;

const int N = 100010;
int a[N];
int tt, m, x;
string n;

void push(int x)
{
    for (int i = tt; i >= 0; i--)a[i + 1] = a[i];
    a[0] = x;
    ++tt;
}
void pop()
{
    --tt;
}
void empty()
{
    if (tt == 0)cout << "YES" << endl;
    else cout << "NO" << endl;
}
void query()
{
    cout << a[tt - 1] << endl;
}
int main()
{
    cin >> m;
    while (m--)
    {
        cin >> n;
        if (n == "push")
        {
            cin >> x;
            push(x);
        }
        else if (n == "pop")pop();
        else if (n == "empty")empty();
        else if (n == "query")query();
    }
    return 0;
}