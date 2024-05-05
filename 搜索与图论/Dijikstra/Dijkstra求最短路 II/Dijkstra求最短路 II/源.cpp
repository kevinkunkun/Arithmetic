#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define y second//宏定义pair中的sceond为y

using namespace std;

const int N = 1e6 + 10;//数据范围

typedef pair<int, int> PII;

int n, m;
int h[N], e[N], ne[N], w[N], idx;//邻接表数组
int dist[N];//dijkstra距离数组
bool st[N];//状态数组

//邻接表插入
void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);//初始化所有点与源点的距离为无穷大
	priority_queue<PII, vector<PII>, greater<PII>> heap;//定义一个小根堆，便于取出最小值
	dist[1] = 0;//初始化源点与源点之间的距离为0
	heap.emplace(0, 1);//将源点与源点的距离和其编号1放入堆中

	while (heap.size())//遍历堆
	{
		auto t = heap.top();//取出堆顶元素，即最小元素，即最短边
		heap.pop();//弹出此元素，使循环能够正常终止

		int ver = t.y;//定义ver为此元素的编号
		if (st[ver]) continue;//如果此元素的最短距离已被优化，则跳过
		st[ver] = true;//改变此元素的状态，表示其最短距离已被优化，

		for (int i = h[ver]; i != -1; i = ne[i])//遍历此元素的所有邻接的点
		{
			int j = e[i];//每一次取其邻接的点并存入j中

			//如果临界点与源点之间的距离大于此元素与源点之间的距离加上此元素与其邻接点的距离
			if (dist[j] > dist[ver] + w[i])
			{
				dist[j] = dist[ver] + w[i];//说明此段路径可以被优化，则将此更小值存入其邻接点的dist数组
				heap.emplace(dist[j], j);//并将其邻接点放入堆中，说明此点可以走到，可以用此点来优化路径
			}
		}
	}

	//如果n点对应的dist为无穷大，说明其既未与其他店联通，也没有被优化，输出错误信息-1
	if (dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];//否则说明可以联通或是被优化过，输出最短路径
}
int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	memset(h, -1, sizeof h);//初始化邻接表

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);//将所有点存入邻接表中
	}

	cout << dijkstra() << endl;

	return 0;
}