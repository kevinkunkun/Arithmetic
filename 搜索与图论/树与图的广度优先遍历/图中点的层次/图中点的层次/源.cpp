#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];

//连接函数
void add(int a,int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

//广度优先遍历函数
int bfs()
{
	memset(d, -1, sizeof d);//初始化d数组，全为-1

	queue<int> q;

	d[1] = 0;//将第一个位置与第一个位置之间的距离初始化为0
	q.push(1);//从第一个位置开始向后遍历，所以将1放入队列之中

	while (q.size())
	{
		int t = q.front();//取队列的第一个元素
		q.pop();//将队列的第一个元素弹出，使得while循环能够正常终止

		//这里bfs每一次都会将一个节点的所有子节点全部遍历完，dfs则是递归寻找最终的节点
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];//取每一个节点在图中地对应编号
			if (d[j] == -1)//若没有遍历过
			{
				d[j] = d[t] + 1;//将其遍历并值相对于上一个数(t)加一，表示其相对t与第各位置之间的距离多一
				q.push(j);//将这个元素放入队列，下一次取t则为此数
			}
		}
	}

	return d[n];//返回d[n]（d[n]代表n与第一个点之间的距离）
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	memset(h, -1, sizeof h);//初始化h数组，使其全为尾节点-1

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}

	cout << bfs() << endl;

	return 0;
}