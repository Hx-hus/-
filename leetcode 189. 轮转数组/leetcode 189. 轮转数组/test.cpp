#define _CRT_SECURE_NO_WARNINGS 1 

#include<vector>
#include<algorithm>

void remove(vector<int>& nums, int l, int r)
{
    while (l < r)
    {
        swap(nums[l], nums[r]);
        r--;
        l++;
    }
}
class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        k %= nums.size();
        if (k == 0)
            return;
        remove(nums, 0, nums.size() - 1);
        remove(nums, k, nums.size() - 1);
        remove(nums, 0, k - 1);
    }
};