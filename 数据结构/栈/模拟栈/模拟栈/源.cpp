#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int skt[N], tt;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	
	while (n--)
	{
		string op;
		int x;

		cin >> op;
		if (op == "push")
		{
			cin >> x;
			skt[++tt] = x;//��ջ������Ԫ��x
		}
		else if (op == "pop") tt--;//ȥ��ջ��Ԫ��
		else if (op == "empty") cout << (tt ? "NO" : "YES") << endl;//������Ŀ��������YES��NO
		else cout << skt[tt] << endl;
	}

	return 0;
}