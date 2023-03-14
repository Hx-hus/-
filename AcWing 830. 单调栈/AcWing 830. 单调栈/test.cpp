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
        while (tt && a[tt] >= x)tt--;//当栈还有元素并且栈顶元素大于要插入的元素的时候，栈内弹出元素
        if (!tt)cout << -1 << " ";//当tt等于0的时候，说明栈内找不到比要插入数小的数，输出-1
        else cout << a[tt] << " ";//否则就是找到，输出那个数
        a[++tt] = x;//将这个元素插入栈内
    }
    return 0;
}
