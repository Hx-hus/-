#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<algorithm>

struct ListNode 
{
      int val;
      ListNode *next;
};
 
class Solution {
public:
    ListNode* getInNode(ListNode* headA, ListNode* headB, int c)
    {
        ListNode* A = new ListNode(), * B = new ListNode();
        A = headA, B = headB;
        while (c)
        {
            c--;
            B = B->next;
        }
        while (A)
        {
            if (A == B) return A;
            A = A->next;
            B = B->next;
        }
        return nullptr;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        int n = 0, m = 0;
        ListNode* A = new ListNode(), * B = new ListNode();
        A = headA, B = headB;
        while (A)
        {
            n++;
            A = A->next;
        }
        while (B)
        {
            m++;
            B = B->next;
        }
        int c = abs(m - n);
        if (m >= n) return getInNode(headA, headB, c);
        else  return getInNode(headB, headA, c);
    }
};