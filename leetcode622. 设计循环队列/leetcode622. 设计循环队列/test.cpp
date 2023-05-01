#define _CRT_SECURE_NO_WARNINGS 1 

#include<vector>

using namespace std;

class MyCircularQueue {
public:
    int front;
    int rear;
    int r;
    vector<int> q;
    MyCircularQueue(int k)
    {
        r = k + 1;
        q = vector<int>(r);
        rear = front = 0;
    }

    bool enQueue(int value)
    {
        if ((rear + 1) % r == front) return false;
        q[rear] = value;
        rear = (rear + 1) % r;
        return true;
    }

    bool deQueue()
    {
        if (rear == front) return false;
        front = (front + 1) % r;
        return true;
    }

    int Front()
    {
        if (rear == front) return -1;
        return q[front];
    }

    int Rear()
    {
        if (rear == front) return -1;
        return q[(rear - 1 + r) % r];
    }

    bool isEmpty()
    {
        return rear == front;
    }

    bool isFull()
    {
        return (rear + 1) % r == front;
    }
};