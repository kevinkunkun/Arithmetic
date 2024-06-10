#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> get_divisors(int x)
{
	vector<int> res;
	for (int i = 1; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			res.push_back(i);//����ܹ���������˵����Լ������������
			if (i != x / i) res.push_back(x / i);//�������ԭ����x������һ��Լ����������
		}
	}
	sort(res.begin(), res.end());//�����������������մ�С�����˳�����
	return res;//����res
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

		auto res = get_divisors(x);

		for (auto x : res) cout << x << ' ';//������ʽ����Χbaseed forѭ��
		cout << endl;
	}

	return 0;
}