#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;
char p[N], s[M];
int n, m, ne[N];
int main()
{
	cin >> n >> p + 1 >> m >> s + 1;
	//��next����
	for (int i = 2, j = 0; i <= n; i++)//i��1��ʼʱ��ƥ��ʧ�ܵ�ʱ�򣬾��˵�0��next[0]���ü��㣬��Ϊ���Ǵ�һ��ʼ��ģ�
	{
		while (j && p[i] != p[j + 1])j = ne[j];//��j��û�˵�0���ߵ��±�i��j+1����ȵ�ʱ�򣬾�����һ�����׺��ֱ�����Ϊֹ
		if (p[i] == p[j + 1])j++;//ƥ��ɹ�����׺��һλ
		ne[i] = j;//����׺���ȸ��µ�next���鵱��
	}
	//kmpƥ�����
	for (int i = 1, j = 0; i <= m; i++) 
	{
		while (j && s[i] != p[j + 1])j = ne[j];//����next���鵱�е�˼·����һ�£���ƥ��ʧ�ܵ�ʱ�򣬾���Сһ��ĺ�׺ȥ��s��ƥ��
		if (s[i] == p[j + 1])j++;//ƥ��ɹ�����׺��һλ
		if (j == n)//��j��n��ȵ�ʱ��˵��ƥ������ˣ��ҵ���
		{
			cout << i - n << " ";
			j = ne[j];//ƥ�����ʱ������һ��ƥ���ʱ��Ҫ����ˣ�������˵���һ����׺����
		}
	}
	return 0;
}