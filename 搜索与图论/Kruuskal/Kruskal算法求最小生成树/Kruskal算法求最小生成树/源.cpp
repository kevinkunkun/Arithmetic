#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

//������ݷ�ΧΪ100000���ߵ����ݷ�ΧΪ200000
const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

int n, m;
int p[N];

//����һ���ṹ��洢��
struct Edge {
	int a, b, w;

	//sort�����ڽṹ���ж��壬����һ��<�����ڽṹ���еĺ���
	bool operator <(const Edge& W)const {
		return w < W.w;
	}
}edges[M];

//���鼯�������ڵĺ���
int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

//��³˹�����㷨
int kruskal()
{
	//�����б߰���Ȩ�ش�С��С��������
	sort(edges, edges + m);

	//��ʼ�����е�ĸ��ӹ�ϵ���Լ����Լ�������
	for (int i = 1; i < n; i++) p[i] = i;

	//��ʼ����С������res�������cnt
	int res = 0, cnt = 0;
	for (int i = 0; i < m; i++)
	{
		//�ӽṹ��ȡ������
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;

		//��a��b������
		a = find(a), b = find(b);
		if (a != b)//���a��b�����ڲ�ͬ��˵��û����ͨ����������СȨ�صı�
		{
			p[a] = b;//��b��Ϊa�ĸ��ף��������ӹ�ϵ����������a��b����ͬһ��ͨ����
			res += w;//����С�������������˱���������СȨ�ر�
			cnt++;//��������һ����ʾ�Ѽ���cnt����
		}
	}

	if (cnt != n - 1) return INF;//�������û�м���n-1���ߣ�˵���޷���ͨ���е㣨��û����С��������
	else return res;//���򷵻���С������
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		//�����ݴ���ṹ����
		edges[i] = { a,b,w };
	}

	int t = kruskal();

	if (t == INF) puts("impossible");
	else cout << t << endl;

	return 0;
}