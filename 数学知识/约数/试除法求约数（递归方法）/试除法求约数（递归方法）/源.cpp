#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void get_divisors(int x,int i)
{
	if (i > x / i) return;//如果我们认为的小的约数已经大于大的约数，返回上一层

	if (x % i == 0) cout << i << ' ';//如果满足约数的要求，则输出此约数

	get_divisors(x,i + 1);//递归操作，直至小约数大于大的约数

	/*
	到这一步，说明小的约数已经输出。
	递归开始返回，则从最小约数中的最大的一个开始返回，得到的x/i依旧是最小的，依旧是从小至大的顺序
	*/
	if (x % i == 0 && i != x / i) cout << x / i << ' ';
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
		get_divisors(x,1);//从1开始递归，相当于for循环中的i=1
		cout << endl;
	}

	return 0;
}