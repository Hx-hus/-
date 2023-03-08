#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};
//����ָ��
class Solution {
public:
    int kthToLast(ListNode* head, int k)
    {
        ListNode* quick = head, * slow = head;
        while (k--)//���ÿ�ָ����k��
        {
            quick = quick->next;
        }
        while (quick)//����ָ���ߵ�NULL��ʱ����ָ��Ҳ���ߵ�������k������
        {
            slow = slow->next;
            quick = quick->next;
        }
        return slow->val;
    }
};