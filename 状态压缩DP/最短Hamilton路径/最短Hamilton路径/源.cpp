#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20, M = 1 << N;//数据范围

int n;//顶点数
int f[M][N];//状态转移数组
int w[N][N];//距离权值数组

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n;//录入顶点数

	//录入距离权值
	for (int i = 0; i < n; i++)
		for (int ij = 0; j < n; j++)
			cin >> w[i][j];

	memset(f, 0x3f, sizeof f);//初始化f数组为无穷大，因为是求最小值，需要使用min函数，起始值需要为无穷大

	f[1][0] = 0;//递归基
	for (int i = 0; i < 1 << n; i++)
		for (int j = 0; j < n; j++)
			if (i >> j & 1)//寻找起点
				for (int k = 0; k < n; k++)
					if (i >> k & 1)//寻找终点
						f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);//两点已确定，说明可以进行状态转移

	cout << f[(1 << n) - 1][n - 1] << ' ';//输出答案

	return 0;
}