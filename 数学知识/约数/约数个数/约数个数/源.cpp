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

	unordered_map<int, int> primes;

	while (n--)
	{
		int x;
		cin >> x;
		
		for (int i = 2; i <= x / i; i++)
			while (x % i == 0)
			{
				x /= i;
				primes[i]++;
			}

		if (x > 1) primes[x]++;//�������һ����x/i������������ô���������ָ����һ
	}

	//ģ�⹫ʽ��Լ������=����0�ӵ���һ����������ָ����*����0�ӵ��ڶ�����������ָ������������
	LL res = 1;
	for (auto prime : primes) res = res * (prime.second + 1) % mod;//peime.second��ʾunordered_map�ĵڶ���Ԫ�أ�Ҳ������������ָ��

	cout << res << endl;

	return 0;
}