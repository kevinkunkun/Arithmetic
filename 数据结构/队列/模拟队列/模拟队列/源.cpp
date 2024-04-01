#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N], hh, tt = -1;//hh为全局变量，初始化为0

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
			q[++tt] = x;//在队尾插入x
		}
		else if (op == "pop") hh++;//删去队头，实现模拟队列先进先出
		else if (op == "empty") cout << (q[hh] ? "NO" : "YES") << endl;//三目运算符输出isempty的答案
		else cout << q[hh] << endl;//查询（query）输出队头
	}

	return 0;
}