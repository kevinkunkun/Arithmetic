#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N], hh, tt = -1;//hhΪȫ�ֱ�������ʼ��Ϊ0

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	while (n--)
	{
		string op;
		cin >> op;

		if (op == "push")
		{
			int x;
			cin >> x;
			q[++tt] = x;//�ڶ�β����x
		}
		else if (op == "pop") hh++;//ɾȥ��ͷ��ʵ��ģ������Ƚ��ȳ�
		else if (op == "empty") cout << (q[hh] ? "NO" : "YES") << endl;//��Ŀ��������isempty�Ĵ�
		else cout << q[hh] << endl;//��ѯ��query�������ͷ
	}

	return 0;
}