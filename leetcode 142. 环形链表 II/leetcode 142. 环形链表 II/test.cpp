#define _CRT_SECURE_NO_WARNINGS 1 

 struct ListNode {
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head)
    {
        if (head == nullptr) return nullptr;
        ListNode* slow = new ListNode(), * fast = new ListNode();
        slow = fast = head;
        while (fast)
        {
            if (fast == nullptr || fast->next == nullptr) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode* ptr = new ListNode();
                ptr = head;
                while (ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};