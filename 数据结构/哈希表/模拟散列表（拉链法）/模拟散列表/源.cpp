#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx;

//�������ϲ���x�γ�����
void insert(int x)
{
	/*
	����xΪһ��������
	��xΪ-10����ô������xmod3������Ϊ��2������C++�У�-10%3=-1
	����Ϊ�˱��⸺������������x��N���࣬�õ��Ľ���ټ���N
	�õ��Ľ��һ����һ����������ô��modN�Ϳ��Եõ�������ٹ�ϣ���е�ӳ��ֵ
	*/
	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
}

//�ж�������k�����������Ƿ����x
bool find(int x)
{
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i])
		if (e[i] == x)
			return true;

	return false;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	/*
	��ʼ��h[N], ������ֵȫ����ʼ��Ϊ - 1�����������NULL��
	��ͨ��β�巨�� - 1����������½ڵ�
	�˺��ÿһ��h[i]��i�����i������������������������ĩ�ˣ�����-1��Զ�ĵط���
	*/
	memset(h, -1, sizeof h);

	while (n--)
	{
		int x;
		string op;
		cin >> op >> x;
		if (op == "I") insert(x);
		else
		{
			if (find(x)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}

	return 0;
}