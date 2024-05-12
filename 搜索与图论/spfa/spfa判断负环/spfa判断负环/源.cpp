#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int h[N], e[N], ne[N], w[N], idx;//�ڽӱ�����
int dist[N], cnt[N];//�����������������
bool st[N];//״̬����

//�ڽӱ���뺯��
void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

//�ж��Ƿ���ڸ�������
bool spfa()
{
	queue<int> q;//��ʼ������

	//�����е㶼�������У�������ִ��ڸ����ĵ㵫�Ǵ˵�Դ�㵽����
	for (int i = 1; i <= n; i++)
	{
		st[i] = true;
		q.emplace(i);
	}

	while (q.size())
	{
		int t = q.front();
		q.pop();

		st[t] = false;//���ӵ�Ԫ��״̬����Ϊfalse

		for (int i=h[t]; i != -1; i = ne[i])//������Ԫ�ص��������ڽڵ�
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])//�ж��Ƿ��ܹ��Ż�
			{
				dist[j] = dist[t] + w[i];//�ܹ��Ż����Ż�
				cnt[j] = cnt[t] + 1;//���������д�λ�õ�ֵ������һλ�õ����ּ�һ

				// ���һ��ֻ��n���㣬�Ż��Ĵ���һ��С�ڵ���n
				// ������������ȴ�����˴���n�����֣�˵��һ�����ڸ���������true
				if (cnt[j] >= n) return true;

				if (!st[j])//��������в����ڴ˱���Ԫ��
				{
					q.emplace(j);//�ô�Ԫ�ؼ������
					st[j] = true;//������е�Ԫ��״̬����Ϊtrue
				}
			}
		}
	}

	return false;//�����ڸ����򷵻�false
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//��������Ż�

	cin >> n >> m;

	memset(h, -1, sizeof h);//��ʼ���ڽӱ�

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}

	if (spfa()) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}