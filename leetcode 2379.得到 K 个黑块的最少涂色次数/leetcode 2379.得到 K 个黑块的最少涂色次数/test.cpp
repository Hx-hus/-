#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
//��������
class Solution {
public:
    int minimumRecolors(string blocks, int k)
    {
        int l = 0, r = 0, count = 0, res = 0,count1=0;
        while (r < k)
        {
            if (blocks[r] == 'W') ++count;
            r++;
        }//����ָ���ƶ���������λ��
        res = count1 = count;
        //ά��
        while (blocks[r])
        {
            if (blocks[l] == 'W')--res;//�����ڵ�����ǰ׵ļ�һ
            if (blocks[r] == 'W')++res;//�����ڵ�����ǰ׵ļ�һ
            count1 = min(count1,min(res,count));//�ȳ���С��һ��
            ++l;
            ++r;
        }
        return count1;
    }
};
int main()
{
    string a;
    Solution b;
    cin >> a;
    cout << b.minimumRecolors(a,2);
    return 0;
}