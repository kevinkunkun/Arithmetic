#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

//快速幂算法
int qmi(int a, int b, int p)
{
	LL res = 1;
	while (b)
	{
		if (b & 1) res = res * a % p;
		a = a * (LL)a % p;
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

	while (n--)
	{
		int a, p;
		cin >> a >> p;
		if (a % p == 0) cout << "impossible" << endl;//如果a是p的倍数，依据费马小定理可知不存在逆元
		else cout << qmi(a, p - 2, p) << endl;//如果a不是p的倍数，依据费马小定理与逆元的定理，通过快速幂算法输出答案
	}

	return 0;
}