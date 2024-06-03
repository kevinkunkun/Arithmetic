#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N], d[N][N];
queue<PII> q;

int bfs()
{
	memset(d, -1, sizeof d);//将d数组全部赋值为-1，方便后续判断，为赋值的即为-1

	d[0][0] = 0;//将原点赋值为0
	q.push({ 0,0 });//将原点加入队列

	int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };//上下左右坐标

	while (q.size())//当q中含有元素时进行
	{
		auto t = q.front();//取t为队列中的队头元素
		q.pop();//弹出q中的对头元素，使得循环能够正常结束

		for (int i = 0; i < 4; i++)//遍历四个方向
		{
			int x = t.x + dx[i], y = t.y + dy[i];//x,y分别是四个方向的横坐标和纵坐标
			//如果x与y没有越界且此点是没有遍历到过的点同时是可以前进的点时
			if (x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1 && g[x][y] == 0)
			{
				d[x][y] = d[t.x][t.y] + 1;//将这个新点的距离更新为上一个点加一
				q.push({ x,y });//将这个点放入队列中
			}
		}
	}
	return d[n - 1][m - 1];//返回终点的距离，即为我们要求的最小距离
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];//输入地图

	cout << bfs() << endl;//输出结果

	return 0;
}