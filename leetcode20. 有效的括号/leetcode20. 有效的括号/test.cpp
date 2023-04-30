#define _CRT_SECURE_NO_WARNINGS 1 

#include<stack>
#include<string>
#include<iostream>

using namespace std;

bool isValid(string s)
{
    if (s.size() % 2 == 1) return false;
    stack<char> l;
    int i;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') l.push(s[i]);
        else
        {
            if (l.empty()) return false;
            int a = s[i] - l.top();
            if (a == 1 || a == 2) l.pop();
            else return false;
        }
    }
    if (l.empty()) return true;
    else return false;
}

int main()
{
	string s = "{[]}";
    cout << isValid(s);
  
	return 0;
}