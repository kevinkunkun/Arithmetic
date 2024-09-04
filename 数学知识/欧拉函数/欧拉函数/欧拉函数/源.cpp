#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//欧拉函数
int phi(int x)
{
	int res = x;
	for (int i = 2; i <= x / i; i++)
		if (x % i == 0)
		{
			//公式：欧拉函数=x*（(第一个质因数-1)/第一个质因数）*（(第二个质因数-1)/第二个质因数）···
			res = res / i * (i - 1);//先除后乘避免溢出
			while (x % i == 0) x /= i;//去掉x中所有的质因数i
		}
	if (x > 1) res = res / x * (x - 1);//如果存在比x/i更大的质因数，加入欧拉函数的计算

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
		int x;
		cin >> x;
		cout << phi(x) << endl;
	}

	return 0;
}