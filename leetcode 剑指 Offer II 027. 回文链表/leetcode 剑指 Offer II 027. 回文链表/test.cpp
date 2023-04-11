#define _CRT_SECURE_NO_WARNINGS 1 


struct ListNode {
    int val;
    ListNode* next;
};
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* newhead = nullptr, * tail = nullptr, * cur = head;
        while (cur)
        {
            head = head->next;
            if (newhead == nullptr)
            {
                newhead = tail = cur;
                newhead->next = nullptr;
            }
            else
            {
                newhead = cur;
                newhead->next = tail;
                tail = newhead;
            }
            cur = head;
        }
        return newhead;
    }

    bool isPalindrome(ListNode* head)
    {
        ListNode* slow = new ListNode(), * fast = new ListNode();
        slow = fast = head;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) fast = fast->next;
        }
        ListNode* mid = new ListNode();
        mid = reverseList(slow);
        while (mid)
        {
            if (head->val != mid->val) return false;
            head = head->next, mid = mid->next;
        }
        return true;
    }
};