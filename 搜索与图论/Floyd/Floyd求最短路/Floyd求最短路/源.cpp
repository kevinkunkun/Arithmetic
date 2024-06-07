#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, k;
int d[N][N];//邻接矩阵

//弗洛伊德算法三重循环，表示从三维的角度其寻找最短路径
void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				//i到j的路径与i到k在从k到j的距离，做比较后取较小值来优化路径的最小值
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	//初始化邻接矩阵，将所有自环设置为0，其他的设置为INF
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;

	//录入路径
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);//当含有相同的路径时，取最短的一条
	}

	floyd();//调用弗洛伊德算法

	//录入询问
	while (k--)
	{
		int a, b;
		cin >> a >> b;

		int t = d[a][b];//取t为a到b的最短路径

		//因为存在负权，所以采用t是否大于0x3f3f3f3f/2的方式判断是否存在路径
		if (t > 0x3f3f3f3f / 2) cout << "impossible" << endl;
		else cout << t << endl;//存在路径则输出最短路径
	}

	return 0;
}