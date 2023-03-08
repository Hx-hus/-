#define _CRT_SECURE_NO_WARNINGS 1 

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};
//双指针
class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* small_x = new ListNode(0), * small_H = small_x;
        ListNode* large_x = new ListNode(0), * large_H = large_x;
        ListNode* cur = head;
        //迭代，将小于x和大于x的分开
        while (cur)
        {
            if (cur->val < x)
            {
                small_x->next = cur;
                small_x = small_x->next;
            }
            else
            {
                large_x->next = cur;
                large_x = large_x->next;
            }
            cur = cur->next;
        }
        //合并到一起
        large_x->next = nullptr;
        small_x->next = large_H->next;
        return small_H->next;
    }
};
