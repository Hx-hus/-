#define _CRT_SECURE_NO_WARNINGS 1 

#include<stack>

using namespace std;


class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue()
    {

    }

    void push(int x)
    {
        s2.push(x);
    }

    int pop()
    {
        if (s1.empty())
        {
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        int a = s1.top();
        s1.pop();
        return a;
    }

    int peek()
    {
        if (s1.empty())
        {
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        return s1.top();
    }

    bool empty()
    {
        if (s1.empty() && s2.empty()) return true;
        return false;
    }
};