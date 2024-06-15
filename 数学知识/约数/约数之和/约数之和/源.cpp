#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int N = 210, mod = 1e9 + 7;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	unordered_map<int, int> primes;//primes�е�һ���������������ڶ���������������ָ��

	while (n--)
	{
		int x;
		cin >> x;

		//��������һ�����ֽ�Ϊ�����������Ĵη�������ʽ
		for (int i = 2; i <= x / i; i++)
			while (x % i == 0)
			{
				x /= i;
				primes[i]++;
			}
		if (x > 1) primes[x]++;
	}

	LL res = 1;
	for (auto prime : primes)
	{
		int a = prime.first, b = prime.second;//ȡaΪ��������bΪָ��
		LL t = 1;

		//ģ�⹫ʽ��Լ��֮��=����һ����������0�η��ӵ�ָ���η���*���ڶ�����������0�η��ӵ�ָ���η���������
		while (b--) t = (t * a + 1) % mod;
		res = res * t % mod;
	}

	cout << res << endl;

	return 0;
}