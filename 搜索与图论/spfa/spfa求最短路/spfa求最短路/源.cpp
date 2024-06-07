#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int h[N], e[N], ne[N], w[N], idx;//邻接表数组
int dist[N];//距离数组
bool st[N];//状态数组,true为在队列中，false表示不在队列中

//邻接表插入函数
void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

//bellman-ford算法的优化，可将O(nm)的时间复杂度优化至O(m)-O(nm)之间
int spfa()
{
	memset(dist, 0x3f, sizeof dist);//初始化dist数组，使所有点距源之间的距离为无穷大
	dist[1] = 0;//初始化源点与源点之间的距离为0
	
	queue<int> q;//初始化队列
	q.emplace(1);//将源点加入队列

	while (q.size())
	{
		int t = q.front();
		q.pop();

		st[t] = false;//弹出队列的元素设置状态为false

		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])//判断是否能够优化
			{
				dist[j] = dist[t] + w[i];//能够优化则进行优化
				if (!st[j])//如果队列中没有此元素
				{
					q.emplace(j);//将其加入队列
					st[j] = true;//加入队列的元素状态设置为true
				}
			}
		}
	}
	
	return dist[n];//返回距离
}
int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	memset(h, -1, sizeof h);

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);//将点与权重录入邻接表
	}

	int t = spfa();

	if (t == 0x3f3f3f3f) cout << "impossible" << endl;//如果没有被联通或优化，输出错误信息imposooble
	else cout << t << endl;//否者输出距离

	return 0;
}