#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 100010;

int n, m, k;
int dist[N];
int last[N];//bellman-ford�㷨�ص㣺backup����洢��������һ�εĸ���ֵ

//bellman-ford�㷨�ص㣺�ṹ��洢����Ȩ��
struct {
	int a, b, c;
}edge[M];

void bellman_ford()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	for (int i = 0; i < k; i++)//�ܴ����ı���
	{
		memcpy(last, dist, sizeof dist);//�洢��һ�εĸ���ֵ
		for (int j = 0; j < m; j++)//�������е�
		{
			auto e = edge[j];//�����Ķ����洢ÿһ�εı���ֵ

			//�����Ż�����������·��ֵ
			//ÿһ��ʹ�õ�һ��ѭ���е�ֵ���бȽϣ�������һ�εĸ���Ӱ����һ�εıȽ�
			dist[e.b] = min(dist[e.b], last[e.a] + e.c);
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	//¼������·���Ľڵ���Ȩ��
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { a,b,c };
	}

	bellman_ford();//ʹ��bellman-ford�㷨�Ż�·��

	//��Ϊ���ڸ�Ȩ
	//�����е�������п��ܱ��ӳ�һ��С��0x3f3f3f3f��ֵ
	//���ֲ���С����һ�룬�ô˱��ʽ���ɱ�ʾ���в��ܵ���ĵ�
	if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
	else cout << dist[n] << endl;//������ڣ����������СȨ��ֵ

	return 0;
}