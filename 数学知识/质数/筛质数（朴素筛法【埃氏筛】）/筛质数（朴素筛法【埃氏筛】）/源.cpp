#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int n;
int primes[N], cnt;//primes：储存质数的数组，cnt：记录质数个数的计数器
bool st[N];//状态数组，表示此数是否为质数（是为false，不是为true）

//希腊数学家埃拉托斯特尼发明的筛法：埃氏筛
void get_primes(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (st[i]) continue;//如果为被删除的数，则跳过此循环的后半部分，即不录入数组
		primes[cnt++] = i;//将每一个质数录入数组primes
		for (int j = i * 2; j <= n; j += i) st[j] = true;//遍历所有i的整数倍的数，将其全部删除（标记为true）
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;

	get_primes(n);


	cout << cnt << endl;

	return 0;
}