#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;//录入物品个数与背包体积

	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];//录入每个物品的体积与价值

	/*
	优化为两重循环，因为完全背包的状态转移方程为：f[i][j] = max(f[i][j], f[i][j - k * v[i]] + k * w[i])
	通过递推发现发f[i][j]与f[i][j-v]的值只相差w[i],所以可以通过滚动数组进行优化
	*/

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = f[i - 1][j];
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
		}
	cout << f[n][m] << endl;

	return 0;
}