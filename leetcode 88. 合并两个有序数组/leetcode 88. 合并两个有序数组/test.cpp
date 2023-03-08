#define _CRT_SECURE_NO_WARNINGS 1 

#include<vector>
using namespace std;

//逆序双指针
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int p1 = m - 1;
        int p2 = n - 1;
        int tail = m + n - 1;
        int tmp;
        while (p1 >= 0 || p2 >= 0)//双指针，因为后面全是0,则可以从后向前来遍历，大的放后面，小的放前面
        {
            if (p1 == -1)tmp = nums2[p2--];
            else if (p2 == -1)tmp = nums1[p1--];
            else if (nums1[p1] > nums2[p2])tmp = nums1[p1--];
            else tmp = nums2[p2--];
            nums1[tail--] = tmp;
        }
    }//不用考虑nums1内的元素被覆盖的情况
};