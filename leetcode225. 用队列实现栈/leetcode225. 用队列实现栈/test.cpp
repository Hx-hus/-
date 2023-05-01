#define _CRT_SECURE_NO_WARNINGS 1 

#include<algorithm>
#include<queue>

using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {

    }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        int a = q1.front();
        q1.pop();
        return a;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};