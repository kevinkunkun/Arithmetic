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

		if (x > 1) primes[x]++;//如果存在一个比x/i的质因数，那么让这个数的指数加一
	}

	//模拟公式：约数个数=（从0加到第一个质因数的指数）*（从0加到第二个质因数的指数）····
	LL res = 1;
	for (auto prime : primes) res = res * (prime.second + 1) % mod;//peime.second表示unordered_map的第二个元素，也就是质因数的指数

	cout << res << endl;

	return 0;
}