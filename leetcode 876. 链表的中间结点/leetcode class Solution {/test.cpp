#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};
//快慢指针
class Solution {
public:
    ListNode* middleNode(ListNode* head)
    {
        if (head->next == NULL) return head;//当内部只有一个节点的时候，直接返回头
        ListNode* quick = head, * slow = head;//快慢指针
        while (quick != NULL && quick->next != NULL)//当快指针不等于NULL和它的下一个节点不等于空的时候进循环更新快慢指针
        {
            slow = slow->next;//慢指针一次走一步
            quick = quick->next->next;//快指针一次有两步
        }
        return slow;//因为快指针走的步数是慢指针的两倍，当快指针走到最后的时候，慢指针就走到了中间
    }
};

