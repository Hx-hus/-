#define _CRT_SECURE_NO_WARNINGS 1 

#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;//�������������������Ϊ��ֱ�ӷ���
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[j] != nums[i])
                nums[++j] = nums[i];//����ȵ�ʱ��ͬʱ���������jͣ��
        }
        return j + 1;//j�������±꣬��1������������ĳ���
    }
};