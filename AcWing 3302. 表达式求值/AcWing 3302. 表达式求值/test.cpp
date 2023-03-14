#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

stack<int> nums;//���ڷ�����
stack<char> op;//��������
string n;//���ַ�����������ʽ
unordered_map<char, int> op_h{ {'+',1},{'-',1},{'*',2},{'/',2} };//���ȼ����⣬

//����ĺ���
void algo()
{
    int a = nums.top();//�õ�����1
    nums.pop();//������1��ջ��ɾ��
    int b = nums.top();//�õ�����2
    nums.pop();//������2��ջ��ɾ��
    char p = op.top();//�Ӵ���������ջ�ó������
    op.pop();//ɾ��ջ�������

    int num = 0;//���ڼ�������
    if (p == '+')num = a + b;
    else if (p == '-')num = b - a;
    else if (p == '*')num = a * b;
    else if (p == '/')num = b / a;

    nums.push(num);//���������ջ���������´μ���
}

int main()
{
    cin >> n;
    int ns = n.size();
    for (int i = 0; i < ns; i++)
    {
        if (isdigit(n[i]))//�ж��ǲ�������
        {
            int x = 0, j = i;
            while (j < ns && isdigit(n[j]))//�����־ͷŵ�ջ��
            {
                x = x * 10 + n[j] - '0';
                j++;
            }
            nums.push(x);
            i = j - 1;//����֮��i++һ�Σ��������︳ֵj-1
        }
        else if (n[i] == '(')//����������žͼ��뵽ջ��
        {
            op.push(n[i]);
        }
        else if (n[i] == ')')//������
        {
            while (op.top() != '(')//���������ȼ��㣬֪����������������
                algo();
            op.pop();
        }
        else
        {
            while (op.size() && op_h[op.top()] >= op_h[n[i]])//�������������ջ������������ȼ�����Ҫ�ŵ�ջ�����������ʱ�����ȼ���ջ�������
                algo();
            op.push(n[i]);//��ջ�������С��Ҫ������������ʱ�򣬲��뵽ջ��
        }
    }
    while (op.size())algo();//�������ջ����Ķ�����գ�������
    cout << nums.top() << endl;
    return 0;
}
