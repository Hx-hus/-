#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};
//����ָ��
class Solution {
public:
    ListNode* middleNode(ListNode* head)
    {
        if (head->next == NULL) return head;//���ڲ�ֻ��һ���ڵ��ʱ��ֱ�ӷ���ͷ
        ListNode* quick = head, * slow = head;//����ָ��
        while (quick != NULL && quick->next != NULL)//����ָ�벻����NULL��������һ���ڵ㲻���ڿյ�ʱ���ѭ�����¿���ָ��
        {
            slow = slow->next;//��ָ��һ����һ��
            quick = quick->next->next;//��ָ��һ��������
        }
        return slow;//��Ϊ��ָ���ߵĲ�������ָ�������������ָ���ߵ�����ʱ����ָ����ߵ����м�
    }
};

