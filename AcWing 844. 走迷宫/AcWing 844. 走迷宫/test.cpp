#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;

int n, m;
const int N = 110;
int maze[N][N], d[N][N];//maze���Թ��������Թ���d�������ж��Թ���Щ���߹�
queue<PII> q;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };//���ж���������ʱ��x��y���ϼ���Щ����

int bfs()
{
	memset(d, -1, sizeof d);//�Ƚ�������ȫ�������-1
	d[0][0] = 0;//����һ�������
	q.push({ 0,0 });//д�����
	while (q.size())
	{
		auto t = q.front();//t�����ڵĶ�ͷ����t�����ܲ�����չ����һ��
		q.pop();//�Ѿ����˶�ͷ��Ҫ����һ�㣬��ǰ��qɾ����Ҳ��Ϊѭ���Ľ�������
		for (int i = 0; i < 4; i++)//��dx��dy������Χ��û��·����ͨ
		{
			int x = t.first + dx[i], y = t.second + dy[i];//����Χx��y������
			if (maze[x][y] == 0 && d[x][y] == -1 && x >= 0 && x < n && y >= 0 && y < m)//�ж��������Ƿ������
			{
				d[x][y] = d[t.first][t.second] + 1;//�ҵ���һ�㣬�����1
				q.push({ x,y });//����������
			}
		}
	}
	return d[n - 1][m - 1];//���յ�λ�þ����������λ�÷���ȥ
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