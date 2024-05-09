#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 100010;

int n, m, k;
int dist[N];
int last[N];//bellman-ford算法特点：backup数组存储遍历中上一次的更新值

//bellman-ford算法特点：结构体存储点与权重
struct {
	int a, b, c;
}edge[M];

void bellman_ford()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	for (int i = 0; i < k; i++)//总次数的遍历
	{
		memcpy(last, dist, sizeof dist);//存储上一次的更新值
		for (int j = 0; j < m; j++)//遍历所有点
		{
			auto e = edge[j];//方便阅读，存储每一次的遍历值

			//满足优化条件即更新路径值
			//每一次使用第一次循环中的值进行比较，避免上一次的更新影响下一次的比较
			dist[e.b] = min(dist[e.b], last[e.a] + e.c);
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	//录入所有路径的节点与权重
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { a,b,c };
	}

	bellman_ford();//使用bellman-ford算法优化路径

	//因为存在负权
	//所以有的无穷大有可能被加成一个小于0x3f3f3f3f的值
	//但又不会小于其一半，用此表达式即可表示所有不能到达的点
	if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
	else cout << dist[n] << endl;//如果存在，则输出其最小权重值

	return 0;
}