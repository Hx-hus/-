#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int trie[N][26], cut[N], idx;//trie表示字典树，用二维数组，第一个节点表示当前的下标，后面的26表示的是字母的下标
//cut记录每个字符串出现的次数,idx表示当前的下标
char str[N];//字典树本体
char op;//操作指令
int n;

//字典树中插入
void insert(char str[])
{
	int p = 0;//root节点，根节点
	for (int i = 0; str[i]; i++)//str[i]表示当前字符串是否结束，字符串结束标志为\0，遇到就跳出循环
	{
		int u = str[i] - 'a';//u记录下当前字符的编号，a~z替换成0~25
		if (!trie[p][u])trie[p][u] = ++idx;//如果当前p节点不存在这个字符，就开辟一条路出来
		p = trie[p][u];//更新到要走的这条路的节点
	}
	cut[p]++;//记录下这个字符串结束出现的次数
}

//字典树中查找
int query(char str[])//返回树中子串出现的次数
{
	int p = 0;//root节点
	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';//得到要查找的字符的编号
		if (!trie[p][u])return 0;//在这条分支中找不大这串，直接返回
		p = trie[p][u];//存在，更新到下一个节点
	}
	return cut[p];//返回以这个字符串出现的次数
}

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> op >> str;
		if (op == 'I')insert(str);
		else cout<<query(str)<<endl;
	}
	return 0;
}
