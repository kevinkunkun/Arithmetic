#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

//点的数据范围为100000，边的数据范围为200000
const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

int n, m;
int p[N];

//定义一个结构体存储边
struct Edge {
	int a, b, w;

	//sort排序在结构体中定义，定义一个<符号在结构体中的含义
	bool operator <(const Edge& W)const {
		return w < W.w;
	}
}edges[M];

//并查集中找祖宗的函数
int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

//克鲁斯卡尔算法
int kruskal()
{
	//将所有边按照权重大小从小到大排序
	sort(edges, edges + m);

	//初始化所有点的父子关系，自己是自己的祖宗
	for (int i = 1; i < n; i++) p[i] = i;

	//初始化最小生成树res与计数器cnt
	int res = 0, cnt = 0;
	for (int i = 0; i < m; i++)
	{
		//从结构体取出数据
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;

		//让a与b找祖宗
		a = find(a), b = find(b);
		if (a != b)//如果a与b的祖宗不同，说明没有联通，但又是最小权重的边
		{
			p[a] = b;//让b成为a的父亲，建立父子关系，这样便让a与b处于同一连通块中
			res += w;//让最小生成树假声本此遍历到的最小权重边
			cnt++;//计数器加一，表示已加入cnt条边
		}
	}

	if (cnt != n - 1) return INF;//如果最终没有加入n-1条边，说明无法联通所有点（即没有最小生成树）
	else return res;//否则返回最小生成树
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		//将数据存入结构体中
		edges[i] = { a,b,w };
	}

	int t = kruskal();

	if (t == INF) puts("impossible");
	else cout << t << endl;

	return 0;
}