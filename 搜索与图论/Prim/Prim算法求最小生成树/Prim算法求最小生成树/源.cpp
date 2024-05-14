#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];//邻接矩阵
int dist[N];//距离数组
bool st[N];//状态数组

int prim()
{
	memset(dist, 0x3f, sizeof dist);//输出话所有距离为无穷大

	int res = 0;//初始化最小生成树的和为0
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		//从源点寻找一个距离其最短的点，并对于这个点，判断所有与其相连的点与其之间的最短距离
		for (int j = 1; j <= n; j++)
		{
			//已经在集合中的点不执行，第一个点不执行，距离大的不执行
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;//距离更小说明这就是我们要找的点，直至找到最小的点

			//第一个点不执行，找到的点如果是无穷大，说明已经找到了一条边都没有的点了
			if (i && dist[t] == INF) return INF;

			//第一个点不累加，因为是INF
			//到这一步，说明距离最短的点已经找到了，我们要将这个点对应的边长加入最小生成树中
			if (i) res += dist[t];

			//将此点加入集合之中，循环下一阶段中去寻找的点将会判断与这个点之间的距离
			st[t] = true;

			//由于将此点加入的集合之中，那么其与对应的边长也应该更新，便于循环下一阶段的判断
			//使用已存入邻接矩阵中的距离来更新此点对应的那一行的边长值
			for (int j = 1; j <= n; j++)
				dist[j] = min(dist[j], g[t][j]);
		}
	}

	return res;//返回最短路径
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	memset(g, 0x3f, sizeof g);//将邻接矩阵上的所有点初始化为无穷大

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b], c);//无向图建立双向边，并取最小值去除重边
	}

	int t = prim();//将prim算法的返回值赋给t

	if (t == INF) cout << "impossible" << endl;//如果返回INF则说明不可能
	else cout << t << endl;//反之则输出最小值

	return 0;
}