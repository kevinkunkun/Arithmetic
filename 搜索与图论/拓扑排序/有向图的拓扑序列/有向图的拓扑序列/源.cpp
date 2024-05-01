#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;//�������е����ĸ�����������
int h[N], e[N], ne[N], idx;//�ڽӱ�
int q[N];//ģ���������
int in[N];//�������

//����Ԫ��
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

//��������
bool topsort()
{
	int hh = 0, tt = -1;//��ʼ����ͷ���β

	for (int i = 1; i <= n; i++)
		if (!in[i])
			q[++tt] = i;//��1��n��Ѱ�����Ϊ0���Ǹ��ڵ�

	while (hh <= tt)
	{
		int t = q[hh++];//�����Ϊ��Ľ�㿪ʼ��ȡ�������t��

		for (int i = h[t]; i != -1; i = ne[i])//��������
		{
			int j = e[i];//ȡ���Ϊ0�Ľڵ���ӽڵ�Ϊj
			if (--in[j] == 0)//����˽ڵ�ֻ����һ���ڵ��ָ��ΪΨһ���
				q[++tt] = j;//������ӣ���һ�δ�����㿪ʼ�������ӽڵ�
		}
	}

	//���շ����Ƿ��������n���㣬û�б�������߱�������n���ڵ㶼������������
	//��Ϊtt��-1��ʼ��������tt=n-1
	return tt == n - 1;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	memset(h, -1, sizeof h);//��ʼ���ڽӱ�

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		in[b]++;
	}

	if (topsort())
	{
		for (int i = 0; i < n; i++) cout << q[i] << ' ';
		cout << endl;
	}
	else
		cout << -1 << ' ';

	return 0;
}