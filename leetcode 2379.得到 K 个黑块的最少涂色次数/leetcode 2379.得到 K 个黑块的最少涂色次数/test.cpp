#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
//滑动窗口
class Solution {
public:
    int minimumRecolors(string blocks, int k)
    {
        int l = 0, r = 0, count = 0, res = 0,count1=0;
        while (r < k)
        {
            if (blocks[r] == 'W') ++count;
            r++;
        }//将右指针移动到窗口右位置
        res = count1 = count;
        //维护
        while (blocks[r])
        {
            if (blocks[l] == 'W')--res;//出窗口的如果是白的减一
            if (blocks[r] == 'W')++res;//进窗口的如果是白的加一
            count1 = min(count1,min(res,count));//比出最小的一项
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