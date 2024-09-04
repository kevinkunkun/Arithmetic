#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2010, mod = 1e9 + 7;

int c[N][N];//组合数答案数组

//模拟公式预编译所有组合数的情况，并将答案存入数组之中
void init()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			if (!j) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;

	init();

	cin >> n;

	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << c[a][b] << endl;
	}

	return 0;
}