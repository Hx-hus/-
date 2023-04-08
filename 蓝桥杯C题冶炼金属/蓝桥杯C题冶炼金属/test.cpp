#define _CRT_SECURE_NO_WARNINGS 1 

#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 10010;
int n;
int a, b;

bool cheak1(int a, int b, int m)
{
	return m * b <= a && a * (b - 1) < m;
}

int main()
{
	scanf("%d", &n);
	int l, r;
	int res1 = 1e9, res2 = 1e9;
	while(n--)
	{
		scanf("%d%d", &a, &b);
		l = 1, r = a / b;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (cheak1(a, b, mid)) r = mid;
			else l = mid + 1;
		}
		res1 = min(r, res1);
		int k = res1;
		while (k--)
		{
			if (a / k > b) break;
		}
		res2 = k + 1;
	}
	printf("%d %d\n", res1, res2);
	return 0;
}
//问题描述
//小蓝有一个神奇的炉子用于将普通金属 O 冶炼成为一种特殊金属 X。这个
//炉子有一个称作转换率的属性 V，V 是一个正整数，这意味着消耗 V 个普通金
//属 O 恰好可以冶炼出一个特殊金属 X，当普通金属 O 的数目不足 V 时，无法
//继续冶炼。
//现在给出了 N 条冶炼记录，每条记录中包含两个整数 A 和 B，这表示本次
//投入了 A 个普通金属 O，最终冶炼出了 B 个特殊金属 X。每条记录都是独立
//的，这意味着上一次没消耗完的普通金属 O 不会累加到下一次的冶炼当中。
//根据这 N 条冶炼记录，请你推测出转换率 V 的最小值和最大值分别可能是
//多少，题目保证评测数据不存在无解的情况。
//
// 输入格式
//第一行一个整数 N，表示冶炼记录的数目。
//接下来输入 N 行，每行两个整数 A、B，含义如题目所述。
//
// 输出格式
// 输出两个整数，分别表示 V 可能的最小值和最大值，中间用空格分开。
//
//【样例输入】
//3
//75 3
//53 2
//59 2
// 
//【样例输出】
//20 25

