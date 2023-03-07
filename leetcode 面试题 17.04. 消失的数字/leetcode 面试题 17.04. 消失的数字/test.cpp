#define _CRT_SECURE_NO_WARNINGS 1 

#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int ret = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 1; i <= nums.size(); i++) ret -= i;
        return -ret;
    }
};