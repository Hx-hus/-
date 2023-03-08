#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};
//��ָ��
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        //��һ��Ϊ�յ�ʱ�򣬷�����һ��
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        //��ָ��
        ListNode* head = new ListNode(0, NULL), * cur = head;
        ListNode* Lh1 = list1, * Lh2 = list2;
        //ֻҪ����������һ���ǿյģ�������ѭ��
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
            head = head->next;//����
        }
        //��û�������һ�������������һ��
        if (Lh1 == NULL)head->next = Lh2;
        if (Lh2 == NULL)head->next = Lh1;
        return cur->next;
    }
};