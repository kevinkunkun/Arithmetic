#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];

//���Ӻ���
void add(int a,int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

//������ȱ�������
int bfs()
{
	memset(d, -1, sizeof d);//��ʼ��d���飬ȫΪ-1

	queue<int> q;

	d[1] = 0;//����һ��λ�����һ��λ��֮��ľ����ʼ��Ϊ0
	q.push(1);//�ӵ�һ��λ�ÿ�ʼ�����������Խ�1�������֮��

	while (q.size())
	{
		int t = q.front();//ȡ���еĵ�һ��Ԫ��
		q.pop();//�����еĵ�һ��Ԫ�ص�����ʹ��whileѭ���ܹ�������ֹ

		//����bfsÿһ�ζ��Ὣһ���ڵ�������ӽڵ�ȫ�������꣬dfs���ǵݹ�Ѱ�����յĽڵ�
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];//ȡÿһ���ڵ���ͼ�еض�Ӧ���
			if (d[j] == -1)//��û�б�����
			{
				d[j] = d[t] + 1;//���������ֵ�������һ����(t)��һ����ʾ�����t��ڸ�λ��֮��ľ����һ
				q.push(j);//�����Ԫ�ط�����У���һ��ȡt��Ϊ����
			}
		}
	}

	return d[n];//����d[n]��d[n]����n���һ����֮��ľ��룩
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	memset(h, -1, sizeof h);//��ʼ��h���飬ʹ��ȫΪβ�ڵ�-1

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}

	cout << bfs() << endl;

	return 0;
}