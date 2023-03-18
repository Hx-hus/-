#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;

int n, m;
const int N = 110;
int maze[N][N], d[N][N];//maze是迷宫，读入迷宫，d是用于判断迷宫那些点走过
queue<PII> q;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };//是判断上下左右时的x和y轴上加哪些坐标

int bfs()
{
	memset(d, -1, sizeof d);//先将数组内全部点打上-1
	d[0][0] = 0;//将第一个点读入
	q.push({ 0,0 });//写入队列
	while (q.size())
	{
		auto t = q.front();//t是现在的队头，用t来看能不能拓展到下一层
		q.pop();//已经用了队头，要找下一层，提前将q删掉，也作为循环的结束条件
		for (int i = 0; i < 4; i++)//用dx和dy来找周围有没有路能走通
		{
			int x = t.first + dx[i], y = t.second + dy[i];//找周围x和y的坐标
			if (maze[x][y] == 0 && d[x][y] == -1 && x >= 0 && x < n && y >= 0 && y < m)//判断条件，是否可以走
			{
				d[x][y] = d[t.first][t.second] + 1;//找到下一层，距离加1
				q.push({ x,y });//将这个点入队
			}
		}
	}
	return d[n - 1][m - 1];//将终点位置距离起点的最短位置返回去
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> maze[i][j];

	cout << bfs() << endl;

	return 0;
}