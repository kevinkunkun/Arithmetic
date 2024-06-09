#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int n;

//分解质因数函数
void divide(int x)
{
	//Q1:什么是分解质因数？什么是质因数的底数和指数？
	/*
	A1:一个数的质因数就是这个数可以分解成为的最小质数。
	例如12=2*2*3，那么2和3都是12的质因数，也就是底数，这里2出现了两次，那么底数2的指数就是2
	*/
	//Q2:为什么要从2开始并遍历到x/i呢？
	/*
	A2:因为要遍历所有质数，那么一定要从2开始，因为n中只含有一个大于sqrt(n)的质因数，
	所以只需要遍历到sqrt(n)即可，最后在来处理哪一个最大的质因数即可。
	至于为什么使用x/i来代替sqrt()函数，因为sqrt()函数慢
	*/
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			int s = 0;
			while (x % i == 0) x /= i, s++;
			cout << i << ' ' << s << endl;
		}
	}

	//最后来处理那一个最大的质数，如果x大于1，说明还没有整除但就出循环了，表示存在最大质数
	if (x > 1) cout << x << ' ' << 1 << endl;
	cout << endl;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;

	while (n--)
	{
		int x;
		cin >> x;
		divide(x);
	}

	return 0;
}