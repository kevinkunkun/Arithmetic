#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int e[N], l[N], r[N], idx;

void init()
{
	r[0] = 1, l[1] = 0;//��ʼ�������ڵ㣬��Ϊ��������ʧ���������ҽڵ�
	idx = 2;
}

void insert(int k, int x)
{
	e[idx] = x;//�Ƚ�x��ֵ����idxָ��ָ�������ռ���
	r[idx] = r[k];//��k�ڵ�ָ���Ҳ��ֵ����idxָ���Ҳ��ָ�룬ʵ�ָ���ָ��
	l[idx] = k;//��idx����ָ��ָ��k
	l[r[k]] = idx;//�ϵ�k�ڵ�ָ����ҽڵ����ָ�룬����idxָ��Ľڵ�ָ��k�ڵ�
	r[k] = idx++;//�ϵ�k�ڵ����ָ�룬������ָ��idxָ��Ľڵ㣬����idx�������ٳ��µĿռ䷽����һ�β������
}

void remove(int k)
{
	l[r[k]] = l[k];//��k�ڵ�ָ�����߽ڵ��ֵ����k�ڵ�ָ����ұ߽ڵ����ָ��
	r[l[k]] = r[k];//��k�ڵ�ָ����ұ߽ڵ��ֵ����k�ڵ�ָ�����߽ڵ����ָ��
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	init();

	while (n--)
	{
		string op;
		int x, k;

		cin >> op;
		if (op == "L")
		{
			cin >> x;
			insert(0, x);
		}
		else if (op == "R")
		{
			cin >> x;
			insert(l[1], x);
		}
		else if (op == "D")
		{
			cin >> k;
			remove(k + 1);
			/*
			k + 1ԭ�����Ƶ������k - 1����Ϊ˫����ʼ�մ���һͷһβ������
			����˫����������ʼ����Ҫ�����ռ����洢����ָ��ĳ�ʼλ�ã�
			��������ռ��ռ�ã���ָ���޷��ظ������Ա�ռ�õ�λ�õĿռ䣬
			��������ȫ������ƶ���λ��ʹ��k-1��Ϊk-1+2=k+1.
			*/
		}
			
		else if (op == "IL")
		{
			cin >> k >> x;
			insert(l[k + 1], x);
		}
		else
		{
			cin >> k >> x;
			insert(k + 1, x);
		}
	}

	for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
	cout << endl;

	return 0;
}