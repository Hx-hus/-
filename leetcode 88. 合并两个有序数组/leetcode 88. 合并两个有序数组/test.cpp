#define _CRT_SECURE_NO_WARNINGS 1 

#include<vector>
using namespace std;

//����˫ָ��
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int p1 = m - 1;
        int p2 = n - 1;
        int tail = m + n - 1;
        int tmp;
        while (p1 >= 0 || p2 >= 0)//˫ָ�룬��Ϊ����ȫ��0,����ԴӺ���ǰ����������ķź��棬С�ķ�ǰ��
        {
            if (p1 == -1)tmp = nums2[p2--];
            else if (p2 == -1)tmp = nums1[p1--];
            else if (nums1[p1] > nums2[p2])tmp = nums1[p1--];
            else tmp = nums2[p2--];
            nums1[tail--] = tmp;
        }
    }//���ÿ���nums1�ڵ�Ԫ�ر����ǵ����
};