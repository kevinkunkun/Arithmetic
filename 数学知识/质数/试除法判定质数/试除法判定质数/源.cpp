#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int n;

bool is_prime(int x)
{
	if (x < 2) return false;//如果小于2，肯定不是质数

	//Q1:为什么使用x/i?
	//A1:因为如果一个数不是质数，那么它一定有两个因子，我们每一次只需要遍历到最小的那一个就行了
	//Q2:为什么不适用sqrt(i)?
	//A2:因为sqrt()是一个函数，循环每次调用浪费时间
	//Q3:为什么不使用i*i<x?
	//A3:因为当数据接近于int的最大值时有数据溢出的风险，导致数据变为负数
	for (int i = 2; i <= x / i; i++)
		if (x % i == 0)
			return false;
	return true;
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
		if (is_prime(x)) puts("Yes");
		else puts("No");
	}

	return 0;
}