#define _CRT_SECURE_NO_WARNINGS 1 

#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        const int n = nums.size();
        int count = n, sum[n + 1];
        sum[0] = 0;
        for (int i = 0; i < n; ++i)
            sum[i + 1] = (sum[i] + nums[i]) % p;
        if (sum[n] == 0) return 0;
        unordered_map<int, int> hash;
        for (int i = 0; i <= n; ++i)
        {
            hash[sum[i]] = i;
            auto it = hash.find((sum[i] - sum[n] + p) % p);
            if (it != hash.end())
                count = min(count, i - it->second);
        }
        return count < n ? count : -1;
    }
};