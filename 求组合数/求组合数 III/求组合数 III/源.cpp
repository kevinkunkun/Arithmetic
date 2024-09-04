#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int p;

//快速幂算法用于求逆元
int qmi(int a, int b, int p)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = (LL)res * a % p;
		a = (LL)a * a % p;
		b >>= 1;
	}
	return res;
}

//模拟简化后的组合数公式，最后返回组合数的值
int C(int a, int b, int p)
{
	if (b > a) return 0;
	if (b > a - b) b = a - b;

	int x = 1, y = 1;
	for (int i = 0; i < b; i++)
	{
		x = (LL)x * (a - i) % p;//计算a!/(a-b)!的值,即(a-b)*(a-b+1)*···*a
		y = (LL)y * (i + 1) % p;//计算b!的值
	}
	return (LL)x * qmi(y, p - 2, p) % p;//返回[a!/(a-b)!]*[(b!)的逆元]
}

//卢卡斯公式
int lucas(LL a, LL b, int p)
{
	//卢卡斯公式的最终式要求a与b要小于p，若其中有一个值不小于p，则需要不停的递归处理减小a和b的值
	if (a < p && b < p) return C(a, b, p);
	return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;//递归处理，通过卢卡斯公式减小非大的数a与b的值
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	while (n--)
	{
		LL a, b;
		cin >> a >> b >> p;
		cout << lucas(a, b, p) << endl;
	}

	return 0;
}