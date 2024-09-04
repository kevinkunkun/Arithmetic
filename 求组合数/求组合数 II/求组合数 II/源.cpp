#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, mod = 1e9 + 7;

typedef long long LL;

int fact[N], infact[N];//阶乘数组与阶乘的逆元数组

//快速幂算法求逆元
int qmi(int a, int b, int k)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = (LL)res * a % mod;
		a = (LL)a * a % mod;
		b >>= 1;
	}
	return res;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	fact[0] = infact[0] = 1;//特殊的结成结果，0的阶乘为1，逆元也为1
	for (int i = 1; i < N; i++)//从1开始遍历
	{
		fact[i] = (LL)fact[i - 1] * i % mod;//预编译每一个数的阶乘结果
		infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;//通过快速幂算法与费马小定理预编译阶乘的逆元结果
	}

	int n;
	cin >> n;
	
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << (LL)fact[a] * infact[b] % mod * infact[a - b] % mod << endl;//模拟公式输出结果，除以一个数就等于乘以它的逆元
	}

	return 0;
}