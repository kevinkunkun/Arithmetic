#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//互质数的定义：两个数如果没有除了1以外的其他公因数，则两个数互为互质数
using namespace std;

typedef long long LL;//N太大了会爆int(0--2^31-1)，换成long long（0--2^63-1）

const int N = 1e6 + 10;

int primes[N], cnt;//质数数组，质数计数器
int euler[N];//欧拉函数数组
bool st[N];//判断质数的状态数组，true为非质数，false为质数

//通过线性筛的方式求欧拉函数
void get_euler(int n)
{
	euler[1] = 1;//1的欧拉函数为1
	for (int i = 2; i <= n; i++)
	{
		if (!st[i])
		{
			primes[cnt++] = i;
			euler[i] = i - 1;
		}
		for (int j = 0; primes[j] <= n / i; j++)
		{
			int t = primes[j] * i;
			st[t] = true;
			if (i % primes[j] == 0)
			{
				//如果此数是i的质因数，那么原欧拉函数（euler[i]）中一定存在（1-1/primes[j]),则直接乘上primes[j]即可
				euler[t] = euler[i] * primes[j];
				break;//primes[j]为i的最小质因数时跳出循环
			}

			//如果此数不是i的质因数，那么不仅要在原欧拉函数(euler[i])的基础上乘上primes[j]，还要乘上（1-1/primes[j]),将两者合并得到（primes[j]-1)
			else euler[t] = euler[i] * (primes[j] - 1);）
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	get_euler(n);//欧拉函数

	LL res = 0;
	for (int i = 1; i <= n; i++) res += euler[i];//从1至n累加得到每个数的欧拉函数之和

	cout << res << endl;

	return 0;
}