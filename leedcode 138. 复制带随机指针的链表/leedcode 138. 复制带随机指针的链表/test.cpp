#define _CRT_SECURE_NO_WARNINGS 1

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr) return nullptr;
        Node* newhead = new Node(0), * headtmp = new Node(0);
        headtmp = head;
        Node* newheadt = newhead, * nhead = newhead;
        while (head)
        {
            newhead = head;
            head->next = newhead;
            newhead = newhead->next;
            head = head->next;
        }
        while (newheadt)
        {
            if (newheadt->random);
            else newheadt->random = headtmp->random->next;
            newheadt = newheadt->next;
            headtmp = headtmp->next;
        }
        while (nhead)
        {
            if (nhead->next);
            else nhead->next = nhead->next->next;
            nhead = nhead->next;
        }
        return nhead;
    }
};

int main()
{
    Node* head = new Node(0);
    Node* headt = head;
    head->val = 7;
    head->random = nullptr;
    head->next = new Node(0);
    head = head->next;
    head->val = 13;
    head->random = nullptr;
    head->next = new Node(0);;
    head = head->next;
    head->val = 11;
    head->random = nullptr;
    head->next = new Node(0);
    head = head->next;
    head->val = 10;
    head->random = nullptr;
    head->next = new Node(0);
    head = head->next;
    head->val = 1;
    head->random = nullptr;
    head->next = new Node(0);
    head = head->next;
    Solution a;
    a.copyRandomList(headt);
    return 0;
}