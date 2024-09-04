#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

//long long版的扩展欧几里得算法
LL exgcd(LL a, LL b, LL& x, LL& y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	LL x = 0, a1, m1;
	cin >> a1 >> m1;//录入第一组被除数与mod

	for (int i = 0; i < n - 1; i++)
	{
		LL a2, m2;//录入后n-1组被除数与mod
		cin >> a2 >> m2;
		LL k1, k2;//定义二元不定方程的a与b
		LL d = exgcd(a1, a2, k1, k2);
		if ((m2 - m1) % d)//如果m2-m1不是最小公约数的倍数，说明无解
		{
			x = -1;
			break;
		}

		k1 *= (m2 - m1) / d;//更新k1，让k1成为m2-m1
		LL t = a2 / d;//定义一个t为二元不定方程的通解中的一项
		k1 = (k1 % t + t) % t;//让k1(m2-m1)变成所有解中最小的正整数的那一项

		x = k1 * a1 + m1;//更新x，无所谓的一步

		m1 = k1 * a1 + m1;//更新余数，让其成为引入新方程后的正解
		a1 = abs(a2 / d * a1);//更新a1为a1与a2的最小公倍数
	}

	if (x != -1) x = (m1 % a1 + a1) % a1;//如果有解，那么取最小正整数的那个解

	cout << x << endl;

	return 0;
}