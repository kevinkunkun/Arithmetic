#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N][N], w[N][N], s[N];//因为分了组，所以体积与价值数组需要多一维来记录组号，再加一个s[N]数组记录每一组的物品个数
int f[N];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		for (int j = 1; j <= s[i]; j++)
			cin >> v[i][j] >> w[i][j];
	}

	//分组背包只是在01背包的情况下在体积与价值数组上加上了一维来表示组号
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 0; j--)
			for (int k = 1; k <= s[i]; k++)
				if (v[i][k] <= j)
					f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

	cout << f[m] << endl;

	return 0;
}