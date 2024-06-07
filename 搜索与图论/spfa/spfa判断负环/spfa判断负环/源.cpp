#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int h[N], e[N], ne[N], w[N], idx;//邻接表数组
int dist[N], cnt[N];//距离数组与计数数组
bool st[N];//状态数组

//邻接表插入函数
void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

//判断是否存在负环函数
bool spfa()
{
	queue<int> q;//初始化队列

	//将所有点都丢进队列，避免出现存在负环的点但是此点源点到不了
	for (int i = 1; i <= n; i++)
	{
		st[i] = true;
		q.emplace(i);
	}

	while (q.size())
	{
		int t = q.front();
		q.pop();

		st[t] = false;//出队的元素状态设置为false

		for (int i=h[t]; i != -1; i = ne[i])//遍历此元素的所有相邻节点
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])//判断是否能够优化
			{
				dist[j] = dist[t] + w[i];//能够优化则优化
				cnt[j] = cnt[t] + 1;//计数数组中此位置的值等于上一位置的数字加一

				// 如果一共只有n个点，优化的次数一定小于等于n
				// 但计数数组中却出现了大于n的数字，说明一定存在负环。返回true
				if (cnt[j] >= n) return true;

				if (!st[j])//如果队列中不存在此遍历元素
				{
					q.emplace(j);//让此元素加入队列
					st[j] = true;//加入队列的元素状态更新为true
				}
			}
		}
	}

	return false;//不存在负环则返回false
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n >> m;

	memset(h, -1, sizeof h);//初始化邻接表

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}

	if (spfa()) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}