#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N];

int find(int x)
{
	/*
	��x�ĸ��ڵ㲻��x����ݹ�find��һֱ���ϱ�����
	�˲��������ܹ��ҵ�x�����ڽڵ㣬���ܹ��Ż������㷨��ʱ�临�Ӷȣ�ʵ��·��ѹ��
	ÿһ���ڵ�ֻ�е�һ����Ҫ�������нڵ㵽���ڵ㣬֮���ÿһ�ζ�ֻ��Ҫһ�鼴��
	���Բ��鼯�㷨��ʱ�临�ӶȽӽ���O(1)
	*/
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) p[i] = i;

	while (m--)
	{
		char op;
		int a, b;

		cin >> op >> a >> b;

		//��b�����ڽڵ����a�ڵ�����ڽڵ�ĸ��ڵ㼴ʵ�����������ϵĺϲ�
		if (op == 'M') p[find(a)] = find(b);
		//�������ڵ�ĸ��ڵ���ͬ��˵�������ڵ���ͬһ�����У������"Yes",�������"No"
		else if (find(a) == find(b)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}