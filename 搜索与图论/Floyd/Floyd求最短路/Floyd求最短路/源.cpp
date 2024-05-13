#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, k;
int d[N][N];//�ڽӾ���

//���������㷨����ѭ������ʾ����ά�ĽǶ���Ѱ�����·��
void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				//i��j��·����i��k�ڴ�k��j�ľ��룬���ȽϺ�ȡ��Сֵ���Ż�·������Сֵ
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	//��ʼ���ڽӾ��󣬽������Ի�����Ϊ0������������ΪINF
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;

	//¼��·��
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);//��������ͬ��·��ʱ��ȡ��̵�һ��
	}

	floyd();//���ø��������㷨

	//¼��ѯ��
	while (k--)
	{
		int a, b;
		cin >> a >> b;

		int t = d[a][b];//ȡtΪa��b�����·��

		//��Ϊ���ڸ�Ȩ�����Բ���t�Ƿ����0x3f3f3f3f/2�ķ�ʽ�ж��Ƿ����·��
		if (t > 0x3f3f3f3f / 2) cout << "impossible" << endl;
		else cout << t << endl;//����·����������·��
	}

	return 0;
}