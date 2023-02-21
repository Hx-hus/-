#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 300010;//题目上能用到最大多的数就是2n+m，n和m都是10^5
int n, m;
int a[N], s[N];//a是原数组，s是前缀和
vector<int> alls;//alls用于对a数组内的元素进行映射，离散化操作
vector<pair<int, int>>add, qu;//add用于在哪个点加多少，qu存放的是区间，l和r，所以两个都用pair存放

int find(int x)
{
	//利用二分查找到x在哪
	int l = 0, r = alls.size() - 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		if (alls[mid] >= x)r = mid;
		else l = mid + 1;
	}
	return r + 1;//这里返回r+1是因为后面要使用前缀和，r+1可以让前缀和不考虑边界问题
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x, c;
		cin >> x >> c;
		add.push_back({ x,c });//add存放在哪个点加多少，点是x，c是加多少
		alls.push_back(x);//讲要加的点映射到vector容器当中
	}
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		qu.push_back({ l,r });//存放要求的区间的两个端点
		alls.push_back(l);//将要计算的左端点映射到数组当中
		alls.push_back(r);//将要计算的右端点映射到数组当中
	}
	//去重
	sort(alls.begin(), alls.end());//使内部离散化之后是有序的
	alls.erase(unique(alls.begin(), alls.end()), alls.end());//利用unique函数进行去重
	//unique会将内部元素的重复元素全都放到后面，然后返回后面全是重复元素区间开始的第一位迭代器，再利用erase删除掉这些重复元素
	
	//查找到x的位置，并且加上我们要加的数
	for (auto itme : add)
	{
		int x = find(itme.first);//查找到x的位置
		a[x] += itme.second;//加上要加的值
	}
	//计算出前缀和
	for (int i = 1; i <= alls.size(); i++)s[i] = s[i - 1] + a[i];
	//利用qu内部存放的端点，用前缀和相减得到答案
	for (auto itme : qu)
	{
		int l = find(itme.first), r = find(itme.second);
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}