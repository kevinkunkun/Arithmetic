#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int exgcd(int a, int b, int& x, int& y)
{
	if (!b)
	{
		x = 1, y = 0;//如果b=0，说明x，y只有一组值——1和0
		return a;//由欧几里得算法可知b=0时返回a
	}
	int d = exgcd(b, a % b, x, y);//递归
	int temp = y;//存y的值
	y = x - a / b * y; //按照裴蜀定理变换（a%b）得到y表示的值为（x-a/b*y）
	x = temp;//将原y的值赋给x，由公式变换得到x的值是不变的
	/*
	优化形式
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	*/
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
		int a, b, x, y;
		cin >> a >> b;
		exgcd(a, b, x, y);
		cout << x << ' ' << y << endl;
	}

	return 0;
}