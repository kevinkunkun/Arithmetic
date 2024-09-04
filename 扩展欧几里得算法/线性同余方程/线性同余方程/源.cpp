#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

typedef long long LL;

//拓展欧几里得算法（裴蜀定理）
int exgcd(int a, int b, int& x, int& y)
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

	while (n--)
	{
		int a, b, m;
		cin >> a >> b >> m;

		int x, y;
		int d = exgcd(a, m, x, y);//获取a与m的最小公因子
		if (b % d) cout << "impossible" << endl;//如果b不是d的倍数，说明不存在线性同余方程
		else cout << (LL)b / d * x % m << endl;//如果存在则输出公式推到出的结果，中间结果可能爆int，转用long long存储
	}

	return 0;
}