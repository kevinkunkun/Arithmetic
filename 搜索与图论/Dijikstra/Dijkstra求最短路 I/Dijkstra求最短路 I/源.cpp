#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510;

int n, m;
int dist[N];
int g[N][N];
bool st[N];

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);//初始化dist，dijkstra算法要求初始距离为无穷
	dist[1] = 0;//初始化源点与源点的距离为0

	for (int i = 0; i < n - 1; i++)
	{
		int t = -1;//初始化t，可以为任何值
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;//遍历所有点，找到与i最近的一个点，坐标为t

		st[t] = true;//表示这个点已被优化，之后即无需再次考虑此点 
		//看看这个点能否优化其路径上的点与源点的最短距离
		//若其与远点的距离加上其与待优化的点的距离之和小于待优化点与源点之间的距离
		//那么表示这段距离可以被优化为一个更小的值，即这两段距离和
		for (int j = 1; j <= n; j++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}

	//如果这个点既没有被联通，也没有被优化，说明从源点开始不能到达此点，返回-1
	if (dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];//否则返回n指向的dist数组值
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n >> m;

	memset(g, 0x3f, sizeof g);

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b], c);//若存在重边，则取最小的一条
	}

	cout << dijkstra() << endl;

	return 0;
}