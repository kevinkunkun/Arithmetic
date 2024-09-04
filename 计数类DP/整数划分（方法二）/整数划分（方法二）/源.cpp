#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;//数据范围

int n;//正整数
int f[N][N];//状态表示数组

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n;//录入正整数

	f[1][1] = 1;//总数为1分为1个数的划分为1
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;//按照划分成的两种方案进行状态转移

	int res = 0;
	for (int i = 0; i <= n; i++) res = (res + f[n][i]) % mod;//累加所有总数为n的状态的划分数

	cout << res << endl;//输出结果

	return 0;
}