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

	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k * v[i] <= j; k++)
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);//×´Ì¬×ªÒÆ·½³Ì

	cout << f[n][m] << endl;

	return 0;
}