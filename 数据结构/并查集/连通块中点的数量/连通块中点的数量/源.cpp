#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N], cnt[N];

/*
���鼯�㷨�Ĺؼ����裨�����ں�����
�������������ڣ�������ʵ��ѹ��·��������ʱ�临�Ӷ�
*/
int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		p[i] = i;
		cnt[i] = 1;//��ʼ����ͨ�飬ʹ��ÿһ�����Ӧһ����ͨ�飬���к���һ����
	}

	while (m--)
	{
		string op;
		int a, b;

		cin >> op;
		if (op == "C")
		{
			cin >> a >> b;
			a = find(a), b = find(b);//��ȡ��a��b�����ڽڵ�
			if (a != b)//��a��b�����ڽڵ㲻ͬ��˵������ͬһ������
			{
				p[a] = b;//��a������b����
				cnt[b] += cnt[a];//����a�д��ڵĵ����b���cnt�����У�ʵ��������ͨ�����ͨ
			}
		}
		else if (op == "Q1")
		{
			cin >> a >> b;
			if (find(a) == find(b)) cout << "Yes" << endl;//��a��b��ͬһ��ͨ���������Yes��
			else cout << "No" << endl;//���������No��
		}
		else if (op == "Q2")
		{
			cin >> a;
			cout << cnt[find(a)] << endl;//���a�ڵ�����ڽڵ��cnt����ʾ��һ��ͨ���д��ڵĵ���
		}
	}

	return 0;
}