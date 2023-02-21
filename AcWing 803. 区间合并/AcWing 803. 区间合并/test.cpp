#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> sec;//���ڴ������������˵�

void merge(vector<pair<int, int>> &sec)
{
	vector<pair<int, int>> res;//���ڴ�źϲ��õ�����
	sort(sec.begin(), sec.end());//�������ڲ���������pair��������Ĭ�������õ�һ�����򣬵���һ��������ͬʱ���ڱȽϵڶ���
	int l = -2e9, r = -2e9;
	//����һ�����飬�ϲ�����
	for (auto itme : sec)
	{
		if (r < itme.first)//�������ά����������Ҷ˵���С�ڱ���������˵��ʱ��˵��ά�����������������û�н��������������һ������
		{
			if (l != -2e9)res.push_back({ l,r });//��ά���������˵㲻�Ǳ߽��ʱ�򣬾ͽ����������뵽�ϲ��������������
			l = itme.first, r = itme.second;//����ά������
		}
		//�������С�ڣ���˵�������н������ϲ����䣬��ά��������Ҷ˵���и���
		else r = max(r, itme.second);//�Ա��ĸ���Ȼ����и�������
	}
	if (l != -2e9)res.push_back({ l,r });//���һ���Ƿ�������û�зŽ���������оͷŽ���

	sec = res;//��sec�����ݸ��³�res��

}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		sec.push_back({ l,r });//�����������˵���뵽��������
	}
	
	merge(sec);//�ϲ�����
	cout << sec.size() << endl;
	return 0;
}