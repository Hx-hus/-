#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 100010;
int a[N], tt, n;

int main()
{
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        while (tt && a[tt] >= x)tt--;//��ջ����Ԫ�ز���ջ��Ԫ�ش���Ҫ�����Ԫ�ص�ʱ��ջ�ڵ���Ԫ��
        if (!tt)cout << -1 << " ";//��tt����0��ʱ��˵��ջ���Ҳ�����Ҫ������С���������-1
        else cout << a[tt] << " ";//��������ҵ�������Ǹ���
        a[++tt] = x;//�����Ԫ�ز���ջ��
    }
    return 0;
}
