#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;//整数
int f[N];//状态数组

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n;//录入整数

	f[0] = 1;//0的划分为0，所以f[0]=1
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			f[j] = (f[j] + f[j - i]) % mod;//完全背包模板，变化时结果的求余

	cout << f[n] << endl;//输出结果

	return 0;
}