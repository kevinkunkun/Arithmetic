#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 10;

int n;
char g[N][N];
bool row[N], col[N], dg[N * 2], udg[N * 2];

void dfs(int x, int y, int s)//x表示横坐标，y表示纵坐标，s表示皇后个数
{
	if (s > n) return;//若皇后个数大于总个数，直接返回

	if (y == n) y = 0, x++;//若当y到了每一行的最后一个，即让y等于0，x++跳至下一行

	if (x == n)//如果行数遍历之最后一行
	{
		if (s == n)//且每一个皇后都已填入
		{
			for (int i = 0; i < n; i++) puts(g[i]);//输出结果
			puts("");
		}
		return;
	}

	g[x][y] = '.';//每递归一位置就给其赋值为'.'
	dfs(x, y + 1, s);//如果一列不加皇后，直接跳至下一行

	if (!row[x] && !col[y] && !dg[x + y] && !udg[y - x + n])//如果一个位置上的所在行、列、对角线、反对角线上都没有皇后
	{
		g[x][y] = 'Q';//可以赋值为Q
		row[x] = col[y] = dg[x + y] = udg[y - x + n] = true;//更改状态为已使用
		dfs(x, y + 1, s + 1);//递归操作直至最后一个
		row[x] = col[y] = dg[x + y] = udg[y - x + n] = false;//还原
		g[x][y] = '.';//还原
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	dfs(0, 0, 0);

	return 0;
}