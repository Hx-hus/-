#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
};

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* newhead = NULL, * tail = NULL, * cur = head;//newhead�Ƿ�ת���ͷ�ڵ�
        //tail��newhead����������ת
        while (cur)
        {   
            head = head->next;//�ȸ���head��������һ���ڵ�
            if (newhead == NULL)
            {
                newhead = tail = cur;//��һ�ν�����tail��newhead���³�ͷ�ڵ�
                newhead->next = NULL;//��ͷ�ڵ�ͺ���ڵ�Ͽ���newheadͨ��tail����ǰ��
            }
            else
            {
                newhead = cur;//�ڶ��ν�������newhead
                newhead->next = tail;//������ת
                tail = newhead;//����tailָ���λ��
            }
            cur = head;//����cur
        }
        return newhead;
    }
};