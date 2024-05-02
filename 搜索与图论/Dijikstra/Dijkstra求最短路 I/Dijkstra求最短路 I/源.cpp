#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510;

int n, m;
int dist[N];
int g[N][N];
bool st[N];

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);//��ʼ��dist��dijkstra�㷨Ҫ���ʼ����Ϊ����
	dist[1] = 0;//��ʼ��Դ����Դ��ľ���Ϊ0

	for (int i = 0; i < n - 1; i++)
	{
		int t = -1;//��ʼ��t������Ϊ�κ�ֵ
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;//�������е㣬�ҵ���i�����һ���㣬����Ϊt

		st[t] = true;//��ʾ������ѱ��Ż���֮�������ٴο��Ǵ˵� 
		//����������ܷ��Ż���·���ϵĵ���Դ�����̾���
		//������Զ��ľ������������Ż��ĵ�ľ���֮��С�ڴ��Ż�����Դ��֮��ľ���
		//��ô��ʾ��ξ�����Ա��Ż�Ϊһ����С��ֵ���������ξ����
		for (int j = 1; j <= n; j++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}

	//���������û�б���ͨ��Ҳû�б��Ż���˵����Դ�㿪ʼ���ܵ���˵㣬����-1
	if (dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];//���򷵻�nָ���dist����ֵ
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//��������Ż�

	cin >> n >> m;

	memset(g, 0x3f, sizeof g);

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b], c);//�������رߣ���ȡ��С��һ��
	}

	cout << dijkstra() << endl;

	return 0;
}