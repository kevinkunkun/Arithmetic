#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define y second//�궨��pair�е�sceondΪy

using namespace std;

const int N = 1e6 + 10;//���ݷ�Χ

typedef pair<int, int> PII;

int n, m;
int h[N], e[N], ne[N], w[N], idx;//�ڽӱ�����
int dist[N];//dijkstra��������
bool st[N];//״̬����

//�ڽӱ����
void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);//��ʼ�����е���Դ��ľ���Ϊ�����
	priority_queue<PII, vector<PII>, greater<PII>> heap;//����һ��С���ѣ�����ȡ����Сֵ
	dist[1] = 0;//��ʼ��Դ����Դ��֮��ľ���Ϊ0
	heap.emplace(0, 1);//��Դ����Դ��ľ��������1�������

	while (heap.size())//������
	{
		auto t = heap.top();//ȡ���Ѷ�Ԫ�أ�����СԪ�أ�����̱�
		heap.pop();//������Ԫ�أ�ʹѭ���ܹ�������ֹ

		int ver = t.y;//����verΪ��Ԫ�صı��
		if (st[ver]) continue;//�����Ԫ�ص���̾����ѱ��Ż���������
		st[ver] = true;//�ı��Ԫ�ص�״̬����ʾ����̾����ѱ��Ż���

		for (int i = h[ver]; i != -1; i = ne[i])//������Ԫ�ص������ڽӵĵ�
		{
			int j = e[i];//ÿһ��ȡ���ڽӵĵ㲢����j��

			//����ٽ����Դ��֮��ľ�����ڴ�Ԫ����Դ��֮��ľ�����ϴ�Ԫ�������ڽӵ�ľ���
			if (dist[j] > dist[ver] + w[i])
			{
				dist[j] = dist[ver] + w[i];//˵���˶�·�����Ա��Ż����򽫴˸�Сֵ�������ڽӵ��dist����
				heap.emplace(dist[j], j);//�������ڽӵ������У�˵���˵�����ߵ��������ô˵����Ż�·��
			}
		}
	}

	//���n���Ӧ��distΪ�����˵�����δ����������ͨ��Ҳû�б��Ż������������Ϣ-1
	if (dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];//����˵��������ͨ���Ǳ��Ż�����������·��
}
int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	memset(h, -1, sizeof h);//��ʼ���ڽӱ�

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);//�����е�����ڽӱ���
	}

	cout << dijkstra() << endl;

	return 0;
}