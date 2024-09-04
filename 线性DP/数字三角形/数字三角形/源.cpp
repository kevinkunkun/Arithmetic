#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;//数据范围行数小于500，无穷大取ox3f3f3f3f

int n;//行数
int a[N][N];//每行的数字
int f[N][N];//状态转移数组

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n;//录入行数

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];

	memset(f, -0x3f, sizeof f);//初始化数组，让每一个点都为负无穷

	int res = -INF;//初始化res为负无穷，方便max运算
	f[1][1] = a[1][1];//第一个数无法使用状态转移方程计算，单独计算
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);//状态转移方程

	for (int i = 1; i <= n; i++) res = max(res, f[n][i]);//计算结果，取最后一行的最大值

	cout << res << endl;

	return 0;
}