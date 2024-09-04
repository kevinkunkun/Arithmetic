#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

//快速幂求逆元
int qmi(int a,int b,int p)
{
	int res = 0;
	while (b)
	{
		if (b & 1) res = (LL)res * a % p;
		a = (LL)a * a % p;
		b >>= 1;
	}
	return res;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int res = 1;
	int a = 2 * n, b = n;

	//以下两步简化了求组合数的公式
	for (int i = a; i >= a - b; i--) res = (LL)res * i % mod;
	for (int i = 0; i < b; i++) res = (LL)res * qmi(i, mod - 2, mod) % mod;

	//将计算出的组合数乘以1/(n+1)得到卡特兰数
	res = (LL)res * qmi(n + 1, mod - 2, mod) % mod;

	cout << res << endl;

	return 0;
}