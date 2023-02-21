#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 300010;//��Ŀ�����õ������������2n+m��n��m����10^5
int n, m;
int a[N], s[N];//a��ԭ���飬s��ǰ׺��
vector<int> alls;//alls���ڶ�a�����ڵ�Ԫ�ؽ���ӳ�䣬��ɢ������
vector<pair<int, int>>add, qu;//add�������ĸ���Ӷ��٣�qu��ŵ������䣬l��r��������������pair���

int find(int x)
{
	//���ö��ֲ��ҵ�x����
	int l = 0, r = alls.size() - 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		if (alls[mid] >= x)r = mid;
		else l = mid + 1;
	}
	return r + 1;//���ﷵ��r+1����Ϊ����Ҫʹ��ǰ׺�ͣ�r+1������ǰ׺�Ͳ����Ǳ߽�����
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x, c;
		cin >> x >> c;
		add.push_back({ x,c });//add������ĸ���Ӷ��٣�����x��c�ǼӶ���
		alls.push_back(x);//��Ҫ�ӵĵ�ӳ�䵽vector��������
	}
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		qu.push_back({ l,r });//���Ҫ�������������˵�
		alls.push_back(l);//��Ҫ�������˵�ӳ�䵽���鵱��
		alls.push_back(r);//��Ҫ������Ҷ˵�ӳ�䵽���鵱��
	}
	//ȥ��
	sort(alls.begin(), alls.end());//ʹ�ڲ���ɢ��֮���������
	alls.erase(unique(alls.begin(), alls.end()), alls.end());//����unique��������ȥ��
	//unique�Ὣ�ڲ�Ԫ�ص��ظ�Ԫ��ȫ���ŵ����棬Ȼ�󷵻غ���ȫ���ظ�Ԫ�����俪ʼ�ĵ�һλ��������������eraseɾ������Щ�ظ�Ԫ��
	
	//���ҵ�x��λ�ã����Ҽ�������Ҫ�ӵ���
	for (auto itme : add)
	{
		int x = find(itme.first);//���ҵ�x��λ��
		a[x] += itme.second;//����Ҫ�ӵ�ֵ
	}
	//�����ǰ׺��
	for (int i = 1; i <= alls.size(); i++)s[i] = s[i - 1] + a[i];
	//����qu�ڲ���ŵĶ˵㣬��ǰ׺������õ���
	for (auto itme : qu)
	{
		int l = find(itme.first), r = find(itme.second);
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}