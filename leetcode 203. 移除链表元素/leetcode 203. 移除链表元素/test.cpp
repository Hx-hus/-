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
        ListNode* guard = new ListNode(0, head);//����һ���ڱ�λ
        ListNode* tail = guard;//���ڱ�λ����
        while (tail->next)//�жϣ���Ϊ�յ�ʱ����������Ϊ���ڱ�λ��������û����ֵ�ģ�����Ҫ�ж���һ��
        {
            if (tail->next->val == val)//�ж��Ƿ����
            {
                tail->next = tail->next->next;//�����ȥ���ýڵ�
            }
            else
            {
                tail = tail->next;//����
            }
        }
        return guard->next;//�����ڱ�λ����һ���ڵ�Ҳ����ͷ�ڵ�
    }
};