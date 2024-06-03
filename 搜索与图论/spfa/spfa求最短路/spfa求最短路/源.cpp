#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int h[N], e[N], ne[N], w[N], idx;//�ڽӱ�����
int dist[N];//��������
bool st[N];//״̬����,trueΪ�ڶ����У�false��ʾ���ڶ�����

//�ڽӱ���뺯��
void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

//bellman-ford�㷨���Ż����ɽ�O(nm)��ʱ�临�Ӷ��Ż���O(m)-O(nm)֮��
int spfa()
{
	memset(dist, 0x3f, sizeof dist);//��ʼ��dist���飬ʹ���е��Դ֮��ľ���Ϊ�����
	dist[1] = 0;//��ʼ��Դ����Դ��֮��ľ���Ϊ0
	
	queue<int> q;//��ʼ������
	q.emplace(1);//��Դ��������

	while (q.size())
	{
		int t = q.front();
		q.pop();

		st[t] = false;//�������е�Ԫ������״̬Ϊfalse

		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])//�ж��Ƿ��ܹ��Ż�
			{
				dist[j] = dist[t] + w[i];//�ܹ��Ż�������Ż�
				if (!st[j])//���������û�д�Ԫ��
				{
					q.emplace(j);//����������
					st[j] = true;//������е�Ԫ��״̬����Ϊtrue
				}
			}
		}
	}
	
	return dist[n];//���ؾ���
}
int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	memset(h, -1, sizeof h);

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);//������Ȩ��¼���ڽӱ�
	}

	int t = spfa();

	if (t == 0x3f3f3f3f) cout << "impossible" << endl;//���û�б���ͨ���Ż������������Ϣimposooble
	else cout << t << endl;//�����������

	return 0;
}