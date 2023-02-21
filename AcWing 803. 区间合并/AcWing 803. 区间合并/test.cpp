#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> sec;//用于存放区间的两个端点

void merge(vector<pair<int, int>> &sec)
{
	vector<pair<int, int>> res;//用于存放合并好的区间
	sort(sec.begin(), sec.end());//将区间内部进行排序，pair类型排序默认先先用第一个排序，当第一个数字相同时候在比较第二个
	int l = -2e9, r = -2e9;
	//遍历一下数组，合并区间
	for (auto itme : sec)
	{
		if (r < itme.first)//如果现在维护的区间的右端点是小于遍历到的左端点的时候，说明维护的区间和所有区间没有交集，进入进行下一步操作
		{
			if (l != -2e9)res.push_back({ l,r });//当维护区间的左端点不是边界的时候，就将这个区间放入到合并区间的容器当中
			l = itme.first, r = itme.second;//更新维护区间
		}
		//如果不是小于，则说明区间有交集，合并区间，将维护区间的右端点进行更新
		else r = max(r, itme.second);//对比哪个大，然后进行更新区间
	}
	if (l != -2e9)res.push_back({ l,r });//检查一下是否还有数组没有放进来，如果有就放进来

	sec = res;//将sec的内容更新成res的

}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		sec.push_back({ l,r });//将区间两个端点放入到容器当中
	}
	
	merge(sec);//合并区间
	cout << sec.size() << endl;
	return 0;
}