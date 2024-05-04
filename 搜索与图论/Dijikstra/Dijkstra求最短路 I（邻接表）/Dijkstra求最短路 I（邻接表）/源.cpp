#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 100010;//���ݷ�Χ�����500���㣬100000����

int n, m;
int h[N], e[M], ne[M], w[M], idx;//�ڽӱ�����
int dist[N];//��������
bool st[N];

//�ڽӱ���뺯��
void add(int a,int b,int c)
{
	e[idx] = b; ne[idx] = h[a]; w[idx] = c; h[a] = idx++;
}

//�Ͻ�˹�����㷨
int dijkstra()
{
	memset(dist, 0x3f,sizeof dist);
	dist[1] = 0;
	
	for (int i = 0; i < n - 1; i++)
	{
		int t = -1;

		//Ѱ����̱�
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;

		//�˵��Լ��뼯��
		st[t] = true;

		//�ô˵������£��Ż��������㵽Դ�����̾���
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			dist[j] = min(dist[j], dist[t] + w[i]);
		}
	}

	if (dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	memset(h, -1, sizeof h);

	cin >> n >> m;

	//�ڽӱ������
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}

	cout << dijkstra() << endl;

	return 0;
}