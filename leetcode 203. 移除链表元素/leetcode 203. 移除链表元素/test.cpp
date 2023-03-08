#define _CRT_SECURE_NO_WARNINGS 1 

using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* guard = new ListNode(0, head);//创建一个哨兵位
        ListNode* tail = guard;//用哨兵位操作
        while (tail->next)//判断，当为空的时候跳出，因为是哨兵位，本身是没有数值的，所以要判断下一个
        {
            if (tail->next->val == val)//判断是否相等
            {
                tail->next = tail->next->next;//相等则去掉该节点
            }
            else
            {
                tail = tail->next;//迭代
            }
        }
        return guard->next;//返回哨兵位的下一个节点也就是头节点
    }
};