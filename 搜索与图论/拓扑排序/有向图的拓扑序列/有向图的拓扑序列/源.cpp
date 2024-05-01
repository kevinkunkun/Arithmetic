#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;//拓扑序列的数的个数与插入次数
int h[N], e[N], ne[N], idx;//邻接表
int q[N];//模拟队列数组
int in[N];//入度数组

//插入元素
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

//拓扑排序
bool topsort()
{
	int hh = 0, tt = -1;//初始化队头与队尾

	for (int i = 1; i <= n; i++)
		if (!in[i])
			q[++tt] = i;//从1至n，寻找入度为0的那个节点

	while (hh <= tt)
	{
		int t = q[hh++];//从入度为零的结点开始，取出其放入t中

		for (int i = h[t]; i != -1; i = ne[i])//遍历链表
		{
			int j = e[i];//取入度为0的节点的子节点为j
			if (--in[j] == 0)//如果此节点只有上一个节点的指向为唯一入度
				q[++tt] = j;//将其入队，下一次从这个点开始遍历其子节点
		}
	}

	//最终返回是否遍历完了n个点，没有遍历完或者遍历超出n个节点都算无拓扑排序
	//因为tt从-1开始，所以是tt=n-1
	return tt == n - 1;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	memset(h, -1, sizeof h);//初始化邻接表

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		in[b]++;
	}

	if (topsort())
	{
		for (int i = 0; i < n; i++) cout << q[i] << ' ';
		cout << endl;
	}
	else
		cout << -1 << ' ';

	return 0;
}