#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];//�ڽӾ���
int dist[N];//��������
bool st[N];//״̬����

int prim()
{
	memset(dist, 0x3f, sizeof dist);//��������о���Ϊ�����

	int res = 0;//��ʼ����С�������ĺ�Ϊ0
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		//��Դ��Ѱ��һ����������̵ĵ㣬����������㣬�ж��������������ĵ�����֮�����̾���
		for (int j = 1; j <= n; j++)
		{
			//�Ѿ��ڼ����еĵ㲻ִ�У���һ���㲻ִ�У������Ĳ�ִ��
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;//�����С˵�����������Ҫ�ҵĵ㣬ֱ���ҵ���С�ĵ�

			//��һ���㲻ִ�У��ҵ��ĵ�����������˵���Ѿ��ҵ���һ���߶�û�еĵ���
			if (i && dist[t] == INF) return INF;

			//��һ���㲻�ۼӣ���Ϊ��INF
			//����һ����˵��������̵ĵ��Ѿ��ҵ��ˣ�����Ҫ��������Ӧ�ı߳�������С��������
			if (i) res += dist[t];

			//���˵���뼯��֮�У�ѭ����һ�׶���ȥѰ�ҵĵ㽫���ж��������֮��ľ���
			st[t] = true;

			//���ڽ��˵����ļ���֮�У���ô�����Ӧ�ı߳�ҲӦ�ø��£�����ѭ����һ�׶ε��ж�
			//ʹ���Ѵ����ڽӾ����еľ��������´˵��Ӧ����һ�еı߳�ֵ
			for (int j = 1; j <= n; j++)
				dist[j] = min(dist[j], g[t][j]);
		}
	}

	return res;//�������·��
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	memset(g, 0x3f, sizeof g);//���ڽӾ����ϵ����е��ʼ��Ϊ�����

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b], c);//����ͼ����˫��ߣ���ȡ��Сֵȥ���ر�
	}

	int t = prim();//��prim�㷨�ķ���ֵ����t

	if (t == INF) cout << "impossible" << endl;//�������INF��˵��������
	else cout << t << endl;//��֮�������Сֵ

	return 0;
}