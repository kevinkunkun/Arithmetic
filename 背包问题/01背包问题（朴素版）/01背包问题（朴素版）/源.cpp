#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];//体积数组v[N]与价值数组w[N]
int f[N][N];//f[i][j]的值表示前i个物品体积不大于j的价值最大值

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = f[i - 1][j];//f[i][j]的划分一：小于i的所有体积不大于j的价值最大值
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);//f[i][j]的划分二：所有小于等于i的体积不大于j的价值最大值【曲线救国：先排除i得到总价值为f[i-1][j-v[i]],再加上i的价值】
		}

	cout << f[n][m] << endl;

	return 0;
}