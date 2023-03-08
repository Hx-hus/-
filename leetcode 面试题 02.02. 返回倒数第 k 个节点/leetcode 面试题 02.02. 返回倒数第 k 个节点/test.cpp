#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};
//快慢指针
class Solution {
public:
    int kthToLast(ListNode* head, int k)
    {
        ListNode* quick = head, * slow = head;
        while (k--)//先让快指针走k步
        {
            quick = quick->next;
        }
        while (quick)//当快指针走到NULL的时候，慢指针也就走到倒数第k个数了
        {
            slow = slow->next;
            quick = quick->next;
        }
        return slow->val;
    }
};