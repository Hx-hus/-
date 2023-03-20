#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;
int h[N], e[N], ne[N], w[N], idx;
int dijk[N];
int n,m;
bool st[N];
int a, b, c;

//���������
void add(int a, int b, int c)
{
	e[idx] = b; ne[idx] = h[a]; w[idx] = c; h[a] = idx++;
}

int dijkstar()
{
	memset(dijk, 0x3f, sizeof dijk);
	dijk[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;//С����
	heap.push({ 0, 1 });//ǰ��ŵ㵽���ľ��룬�����ı��
	while (heap.size())//������Ϊ�յ�ʱ���֤��������
	{
		auto t = heap.top();
		heap.pop();
		int val = t.second;

		if (st[val]) continue;//���������Ѿ�¼�������·
		st[val] = true;//��������û�б����ϱ�ǣ����ھʹ��ϱ��

		for (int i = h[val]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dijk[j] > dijk[val] + w[i])//��������������·����
			{
				dijk[j] = dijk[val] + w[i];
				heap.push({ dijk[j],j });//���µ��ѵ���
			}
		}
	}
	if (dijk[n] == 0x3f3f3f3f)return -1;
	return dijk[n];

}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);

	while (m--)
	{
		cin >> a >> b >> c;
		add(a, b, c);
	}

	cout << dijkstra() << endl;
	return 0;
}
