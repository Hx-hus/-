#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 1000010;
int p[N], n, m, a, b;//p�Ǽ��ϣ�ͨ���������������

int find(int x)
{
    if (p[x] != x)p[x] = find(p[x]);//·���ϲ�������Ѱ�ҵ����ڵ�
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
        if (*op == 'M')p[find(a)] = find(b);//��һ�����Ϻϲ�����һ�����ϣ�ֻ��Ҫ��һ�����ڵ�����һ�����ӽڵ㼴��
        else
        {
            if (find(a) == find(b))cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}