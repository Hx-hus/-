#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

int nums1[510][510], nums2[510][510];//һ����ԭ���飬һ����ģ��������
int n, m, x, y, r, z;

int main()
{
    cin >> n >> m;
    int count = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)nums1[i][j] = count++;//����ȫ�ŵ�ԭ���鵱��
    while (m--)
    {
        cin >> x >> y >> r >> z;
        if (z == 0)//˳ʱ��
        {
            for (int i = x - r; i <= x + r; i++)
                for (int j = y - r; j <= y + r; j++)
                    nums2[x - y + j][x + y - i] = nums1[i][j];//��ħ��״̬�������ŵ�ģ������鵱��
            for (int i = x - r; i <= x + r; i++)
                for (int j = y - r; j <= y + r; j++)
                    nums1[i][j] = nums2[i][j];//����ԭ�����Ϊģ������
        }
        else//��ʱ��
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