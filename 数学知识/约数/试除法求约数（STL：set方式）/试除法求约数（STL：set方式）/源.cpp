#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void get_divisors(int x)
{
	set<int> s;//set���Ͽ���ʵ�ֶ���������ͺϲ���set�����е�����ӵ��˳����ֻ����һ��
	for (int i = 1; i < x / i; i++)
		if (x % i == 0)
			s.insert(i), s.insert(x / i);

	for (auto x : s) cout << x << ' ';//based forѭ��
	cout << endl;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	while (n--)
	{
		int x;
		cin >> x;
		get_divisors(x);
	}

	return 0;
}