#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char c[101][101];
int main()
{
    int a, b;
    cin >> a >> b;//输入矩阵大小
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
        {
            cin >> c[i][j];//输入每个位置上的情况
        }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)//循环输出，判断周围是否有雷
        {
            int sum = 0;
            if (c[i][j] == '*') cout << '*';//如果该位置有雷，直接输出‘*’
            else         //判断，周围有雷自+1；
            {
                if (c[i - 1][j + 1] == '*') sum++;
                if (c[i][j + 1] == '*') sum++;
                if (c[i + 1][j + 1] == '*') sum++;
                if (c[i - 1][j] == '*') sum++;
                if (c[i + 1][j] == '*') sum++;
                if (c[i - 1][j - 1] == '*') sum++;
                if (c[i][j - 1] == '*') sum++;
                if (c[i + 1][j - 1] == '*') sum++;
                cout << sum;//判断完毕后直接输出sum
            }
        }
        cout << endl;//换行
    }
    return 0;
}