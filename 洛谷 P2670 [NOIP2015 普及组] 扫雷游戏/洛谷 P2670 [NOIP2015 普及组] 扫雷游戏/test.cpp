#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char c[101][101];
int main()
{
    int a, b;
    cin >> a >> b;//��������С
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
        {
            cin >> c[i][j];//����ÿ��λ���ϵ����
        }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)//ѭ��������ж���Χ�Ƿ�����
        {
            int sum = 0;
            if (c[i][j] == '*') cout << '*';//�����λ�����ף�ֱ�������*��
            else         //�жϣ���Χ������+1��
            {
                if (c[i - 1][j + 1] == '*') sum++;
                if (c[i][j + 1] == '*') sum++;
                if (c[i + 1][j + 1] == '*') sum++;
                if (c[i - 1][j] == '*') sum++;
                if (c[i + 1][j] == '*') sum++;
                if (c[i - 1][j - 1] == '*') sum++;
                if (c[i][j - 1] == '*') sum++;
                if (c[i + 1][j - 1] == '*') sum++;
                cout << sum;//�ж���Ϻ�ֱ�����sum
            }
        }
        cout << endl;//����
    }
    return 0;
}