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

	unordered_map<int, int> primes;//primes中第一个数是质因数，第二个数是质因数的指数

	while (n--)
	{
		int x;
		cin >> x;

		//此做法将一个数分解为所有质因数的次方积的形式
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
		int a = prime.first, b = prime.second;//取a为质因数，b为指数
		LL t = 1;

		//模拟公式，约数之和=（第一个质因数从0次方加到指数次方）*（第二个质因数从0次方加到指数次方）···
		while (b--) t = (t * a + 1) % mod;
		res = res * t % mod;
	}

	cout << res << endl;

	return 0;
}