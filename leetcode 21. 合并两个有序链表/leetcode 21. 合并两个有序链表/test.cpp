#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};
//三指针
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        //当一方为空的时候，返回另一方
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        //三指针
        ListNode* head = new ListNode(0, NULL), * cur = head;
        ListNode* Lh1 = list1, * Lh2 = list2;
        //只要两个其中有一个是空的，就跳出循环
        while (Lh1 && Lh2)
        {
            if (Lh1->val <= Lh2->val)
            {
                head->next = Lh1;
                Lh1 = Lh1->next;
            }
            else
            {
                head->next = Lh2;
                Lh2 = Lh2->next;
            }
            head = head->next;//迭代
        }
        //将没迭代完的一方与新链表接在一起
        if (Lh1 == NULL)head->next = Lh2;
        if (Lh2 == NULL)head->next = Lh1;
        return cur->next;
    }
};