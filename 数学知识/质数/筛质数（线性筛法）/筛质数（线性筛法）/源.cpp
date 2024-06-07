#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int n;
int primes[N], cnt;//peimes:质数数组；cnt:质数计数器
bool st[N];//状态数组，true为不是质数，false为是质数

//线性筛法
void get_primes(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!st[i]) primes[cnt++] = i;//如果是质数，则加如质数数组中
		for (int j = 0; primes[j] <= n / i; j++)
		{
			st[primes[j] * i] = true;//从质数数组中最小的质数2小开始遍历，删除其与i的乘积这个和数

			//如果primes中某一个数能够整除i，则及结束此次循环，否则继续删除下一个质数与i乘积，直至此质数为i的最小质因数
			if (i % primes[j] == 0) break;
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;

	get_primes(n);

	cout << cnt << endl;

	return 0;
}