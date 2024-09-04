#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

	/*
	通过观察发现可以记进一步优化为一维数组的形式
	因为完全背包问题的状态转移方程与01背包问题的状态转移方程的唯一差别是
	01背包问题需要获取第i-1层的值来更新第i层，所以必须要从后向前更新
	而完全背包问题只需要第i层的值来更新第i层的值，所以必须要从前向后更新满足每一次都能使用第i层的值来更新第i层。
	*/
	for (int i = 1; i <= n; i++)
		for (int j = v[i]; j <= m; j++)
			f[j] = max(f[j], f[j - v[i]] + w[i]);

	cout << f[m] << endl;

	return 0;
}