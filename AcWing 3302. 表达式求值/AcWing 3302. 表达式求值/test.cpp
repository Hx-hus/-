#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

stack<int> nums;//用于放数字
stack<char> op;//存放运算符
string n;//用字符串存运算表达式
unordered_map<char, int> op_h{ {'+',1},{'-',1},{'*',2},{'/',2} };//优先级问题，

//计算的函数
void algo()
{
    int a = nums.top();//拿到数字1
    nums.pop();//将数字1从栈顶删除
    int b = nums.top();//拿到数字2
    nums.pop();//将数字2从栈顶删除
    char p = op.top();//从存放运算符的栈拿出运算符
    op.pop();//删除栈顶运算符

    int num = 0;//用于计算出结果
    if (p == '+')num = a + b;
    else if (p == '-')num = b - a;
    else if (p == '*')num = a * b;
    else if (p == '/')num = b / a;

    nums.push(num);//将结果放在栈顶，方便下次计算
}

int main()
{
    cin >> n;
    int ns = n.size();
    for (int i = 0; i < ns; i++)
    {
        if (isdigit(n[i]))//判断是不是数字
        {
            int x = 0, j = i;
            while (j < ns && isdigit(n[j]))//是数字就放到栈中
            {
                x = x * 10 + n[j] - '0';
                j++;
            }
            nums.push(x);
            i = j - 1;//结束之后i++一次，所以这里赋值j-1
        }
        else if (n[i] == '(')//如果是左括号就加入到栈中
        {
            op.push(n[i]);
        }
        else if (n[i] == ')')//右括号
        {
            while (op.top() != '(')//括号内优先计算，知道遇到左括号跳出
                algo();
            op.pop();
        }
        else
        {
            while (op.size() && op_h[op.top()] >= op_h[n[i]])//其他运算符，当栈顶运算符的优先级大于要放到栈顶的运算符的时候，优先计算栈顶运算符
                algo();
            op.push(n[i]);//当栈顶运算符小于要插入的运算符的时候，插入到栈顶
        }
    }
    while (op.size())algo();//将运算符栈里面的东西清空，计算完
    cout << nums.top() << endl;
    return 0;
}
