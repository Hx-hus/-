#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 1000010;
int p[N], n, m, a, b;//p是集合，通常拿树存这个集合

int find(int x)
{
    if (p[x] != x)p[x] = find(p[x]);//路径合并操作带寻找到根节点
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)p[i] = i;
    while (m--)
    {
        char op[2];
        cin >> op >> a >> b;
        if (*op == 'M')p[find(a)] = find(b);//将一个集合合并到另一个集合，只需要将一个根节点变成另一个的子节点即可
        else
        {
            if (find(a) == find(b))cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}