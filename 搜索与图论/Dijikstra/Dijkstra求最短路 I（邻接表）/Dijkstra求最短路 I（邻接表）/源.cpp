#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 100010;//数据范围：最多500个点，100000条边

int n, m;
int h[N], e[M], ne[M], w[M], idx;//邻接表数组
int dist[N];//距离数组
bool st[N];

//邻接表插入函数
void add(int a,int b,int c)
{
	e[idx] = b; ne[idx] = h[a]; w[idx] = c; h[a] = idx++;
}

//迪杰斯特拉算法
int dijkstra()
{
	memset(dist, 0x3f,sizeof dist);
	dist[1] = 0;
	
	for (int i = 0; i < n - 1; i++)
	{
		int t = -1;

		//寻找最短边
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;

		//此点以加入集合
		st[t] = true;

		//用此点来更新（优化）其他点到源点的最短距离
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			dist[j] = min(dist[j], dist[t] + w[i]);
		}
	}

	if (dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	memset(h, -1, sizeof h);

	cin >> n >> m;

	//邻接表存贮边
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}

	cout << dijkstra() << endl;

	return 0;
}