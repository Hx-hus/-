#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <string>
using namespace std;

const int N = 1000010;
int p[N], n, m, a, b, cut[N];//cut���ڼ�¼��������ж��ٸ��ڵ�

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
        cut[i] = 1;//һ��ʼÿ������1���ڵ�
    }
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "C")
        {
            cin >> a >> b;
            a = find(a), b = find(b);
            if (a != b)//��Ҫ�ж�һ�£���Ϊa��b�������
            {
                p[a] = b;//��a����b���ӽڵ�
                cut[b] += cut[a];//����������ڵĽڵ����
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