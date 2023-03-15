#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <string>
using namespace std;

const int N = 1000010;
int p[N], n, m, a, b, cut[N];//cut用于记录这个树内有多少个节点

int find(int x)
{
    if (p[x] != x)p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        cut[i] = 1;//一开始每个都是1个节点
    }
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "C")
        {
            cin >> a >> b;
            a = find(a), b = find(b);
            if (a != b)//需要判断一下，因为a和b可能相等
            {
                p[a] = b;//将a当做b的子节点
                cut[b] += cut[a];//更新这个树内的节点个数
            }

        }
        else if (op == "Q1")
        {
            cin >> a >> b;
            if (find(a) == find(b))cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else
        {
            cin >> a;
            cout << cut[find(a)] << endl;
        }
    }
    return 0;
}