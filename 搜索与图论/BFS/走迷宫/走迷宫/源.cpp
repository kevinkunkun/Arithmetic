#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N], d[N][N];
queue<PII> q;

int bfs()
{
	memset(d, -1, sizeof d);//��d����ȫ����ֵΪ-1����������жϣ�Ϊ��ֵ�ļ�Ϊ-1

	d[0][0] = 0;//��ԭ�㸳ֵΪ0
	q.push({ 0,0 });//��ԭ��������

	int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };//������������

	while (q.size())//��q�к���Ԫ��ʱ����
	{
		auto t = q.front();//ȡtΪ�����еĶ�ͷԪ��
		q.pop();//����q�еĶ�ͷԪ�أ�ʹ��ѭ���ܹ���������

		for (int i = 0; i < 4; i++)//�����ĸ�����
		{
			int x = t.x + dx[i], y = t.y + dy[i];//x,y�ֱ����ĸ�����ĺ������������
			//���x��yû��Խ���Ҵ˵���û�б��������ĵ�ͬʱ�ǿ���ǰ���ĵ�ʱ
			if (x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1 && g[x][y] == 0)
			{
				d[x][y] = d[t.x][t.y] + 1;//������µ�ľ������Ϊ��һ�����һ
				q.push({ x,y });//���������������
			}
		}
	}
	return d[n - 1][m - 1];//�����յ�ľ��룬��Ϊ����Ҫ�����С����
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);//��������Ż�

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];//�����ͼ

	cout << bfs() << endl;//������

	return 0;
}