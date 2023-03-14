#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int trie[N][26], cut[N], idx;//trie��ʾ�ֵ������ö�ά���飬��һ���ڵ��ʾ��ǰ���±꣬�����26��ʾ������ĸ���±�
//cut��¼ÿ���ַ������ֵĴ���,idx��ʾ��ǰ���±�
char str[N];//�ֵ�������
char op;//����ָ��
int n;

//�ֵ����в���
void insert(char str[])
{
	int p = 0;//root�ڵ㣬���ڵ�
	for (int i = 0; str[i]; i++)//str[i]��ʾ��ǰ�ַ����Ƿ�������ַ���������־Ϊ\0������������ѭ��
	{
		int u = str[i] - 'a';//u��¼�µ�ǰ�ַ��ı�ţ�a~z�滻��0~25
		if (!trie[p][u])trie[p][u] = ++idx;//�����ǰp�ڵ㲻��������ַ����Ϳ���һ��·����
		p = trie[p][u];//���µ�Ҫ�ߵ�����·�Ľڵ�
	}
	cut[p]++;//��¼������ַ����������ֵĴ���
}

//�ֵ����в���
int query(char str[])//���������Ӵ����ֵĴ���
{
	int p = 0;//root�ڵ�
	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';//�õ�Ҫ���ҵ��ַ��ı��
		if (!trie[p][u])return 0;//��������֧���Ҳ����⴮��ֱ�ӷ���
		p = trie[p][u];//���ڣ����µ���һ���ڵ�
	}
	return cut[p];//����������ַ������ֵĴ���
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
