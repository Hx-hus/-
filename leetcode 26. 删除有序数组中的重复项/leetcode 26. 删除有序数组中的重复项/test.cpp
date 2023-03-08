#define _CRT_SECURE_NO_WARNINGS 1 

#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;//处理特殊情况，当数组为空直接返回
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[j] != nums[i])
                nums[++j] = nums[i];//当相等的时候，同时动，不相等j停下
        }
        return j + 1;//j是最后的下标，加1才是整个数组的长度
    }
};