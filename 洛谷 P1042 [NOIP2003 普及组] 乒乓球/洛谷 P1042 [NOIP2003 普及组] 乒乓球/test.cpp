#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cmath>
using namespace std;

int f[2] = { 11,21 };
int a[62600], n;

int main()
{
    char tmp;
    while (1)
    {
        scanf("%c", &tmp);
        if (tmp == 'E') break;
        else if (tmp == 'W') a[n++] = 1;
        else if (tmp == 'L') a[n++] = 2;
    }
    for (int i = 0; i < 2; i++)
    {
        int w = 0, l = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == 1) w++;
            if (a[j] == 2) l++;
            if (max(w, l) >= f[i] && abs(w - l) >= 2)
            {
                cout << w << ":" << l << endl;
                w = l = 0;
            }
        }
        cout << w << ":" << l << endl;
        cout << endl;
    }
    return 0;
}