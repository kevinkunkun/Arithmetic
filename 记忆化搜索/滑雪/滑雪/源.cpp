#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 310;//数据范围

int n, m;//滑雪场的行数与列数
int f[N][N];//状态转移数组
int g[N][N];//高度

int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };//方向数组

//记忆化搜索
int dp(int x, int y)
{
	int& v = f[x][y];//简化代码，让f[x][y]=v
	if (v != -1) return v;//如果v不为初始化的-1，说明已经更新过了，直接返回

	v = 1;//初始化v=1，因为样例中有25个点，距离为25，说明如果只能滑一个点距离为1
	for (int i = 0; i < 4; i++)
	{
		int a = x + dx[i], b = y + dy[i];//上下左右前进进行遍历
		if (a >= 0 && a < n && b >= 0 && b < m && g[x][y]>g[a][b])//可以滑行的条件，不超出滑雪场范围，且比现在的高度低
			v = max(v, dp(a, b) + 1);//满足条件则更新v的值，取与递归结果之间的最大值
	}

	return v;//最后返回得到的v(f[x][y])
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n >> m;//录入行数与列数
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];//录入高度

	memset(f, -1, sizeof f);//初始化状态转移数组

	int res = 0;//初始化距离为0
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res = max(res, dp(i, j));//每一次更新距离最大值

	cout << res << endl;//输出答案

	return 0;
}