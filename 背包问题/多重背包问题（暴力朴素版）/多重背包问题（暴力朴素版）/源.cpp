#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N], s[N];//比完全背包问题多一个是s[N]数组来存发每一个物品的的最多数量
int f[N][N];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];

	//完全参照完全背包的朴素版，只多了一个条件用于限制每个物品的最多个数
	for(int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);

	cout << f[n][m] << endl;

	return 0;
}