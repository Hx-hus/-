#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

int nums1[510][510], nums2[510][510];//一个放原数组，一个放模拟后的数组
int n, m, x, y, r, z;

int main()
{
    cin >> n >> m;
    int count = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)nums1[i][j] = count++;//讲数全放到原数组当中
    while (m--)
    {
        cin >> x >> y >> r >> z;
        if (z == 0)//顺时针
        {
            for (int i = x - r; i <= x + r; i++)
                for (int j = y - r; j <= y + r; j++)
                    nums2[x - y + j][x + y - i] = nums1[i][j];//讲魔法状态后的数组放到模拟后数组当中
            for (int i = x - r; i <= x + r; i++)
                for (int j = y - r; j <= y + r; j++)
                    nums1[i][j] = nums2[i][j];//更新原数组成为模拟数组
        }
        else//逆时针
        {
            for (int i = x - r; i <= x + r; i++)
                for (int j = y - r; j <= y + r; j++)
                    nums2[x + y - j][y - x + i] = nums1[i][j];
            for (int i = x - r; i <= x + r; i++)
                for (int j = y - r; j <= y + r; j++)
                    nums1[i][j] = nums2[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)cout << nums1[i][j] << " ";
        cout << endl;
    }
    return 0;
}