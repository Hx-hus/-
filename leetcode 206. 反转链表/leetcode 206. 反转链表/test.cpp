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
        ListNode* newhead = NULL, * tail = NULL, * cur = head;//newhead是反转后的头节点
        //tail和newhead互相联动反转
        while (cur)
        {   
            head = head->next;//先更新head，保存下一个节点
            if (newhead == NULL)
            {
                newhead = tail = cur;//第一次进，讲tail和newhead更新成头节点
                newhead->next = NULL;//将头节点和后面节点断开，newhead通过tail访问前面
            }
            else
            {
                newhead = cur;//第二次进来更新newhead
                newhead->next = tail;//将链表反转
                tail = newhead;//更新tail指向的位置
            }
            cur = head;//更新cur
        }
        return newhead;
    }
};