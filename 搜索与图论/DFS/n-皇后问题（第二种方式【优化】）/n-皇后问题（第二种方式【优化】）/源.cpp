#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 10;

int n;
char g[N][N];
bool col[N], dg[N * 2], udg[N * 2];//对角线为2n-1条，所以开两倍的空间

void dfs(int x)
{
	if (x == n)
	{
		for (int i = 0; i < n; i++) puts(g[i]);//使用puts比cout更高效且不用写双重循环
		puts("");
		return;
	}

	for (int i = 0; i < n; i++)
		//如果g[x][i]所在列、对角线、反对角线上均无Q，说明可以赋值
		if (!col[i] && !dg[x + i] && !udg[n + i - x])
		{
			g[x][i] = 'Q';//将这一特殊位置赋值为Q
			//将此点的所在列、对角线和反对角线都赋值为true说明已使用
			col[i] = dg[x + i] = udg[n + i - x] = true;
			dfs(x + 1);//递归直至将x遍历完全
			col[i] = dg[x + i] = udg[n + i - x] = false;//还原
			g[x][i] = '.';//还原，下一次遍历即可遍历出另一种结果
		}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = '.';

	dfs(0);

	return 0;
}