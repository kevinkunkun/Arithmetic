#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 6010;//数据范围

int n;//参加聚会人数
int happy[N];//高兴度数组
int h[N], e[N], ne[N], idx;//邻接链表模拟数组
int f[N][2];//状态转移数组
bool has_fa[N];//父节点状态数组

//邻接链表连接函数
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

//递归处理函数
void dfs(int u)
{
	f[u][1] = happy[u];//递归基，当只选根节点时，其高兴度为happy[u]

	for (int i = h[u]; ~i; i = ne[i])//遍历邻接链表
	{
		int j = e[i];//取出每一个节点的值，即职员
		dfs(j);//递归处理此职员，即让其当上司，处理其下属

		f[u][1] += f[j][0];//第一种情况，选此上司，则下属不能选，只能加不选下属的状态
		f[u][0] += max(f[j][1], f[j][0]);//第二种情况，不选此上司，取选下属与不选下属两种情况的高兴度之和的最大值
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n;//录入人数
	for (int i = 1; i <= n; i++)
		cin >> happy[i];//录入高兴度

	memset(h, -1, sizeof h);//初始化所有头节点为-1
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;//录入节点，即职员
		add(b, a);//为职员与上司建立联系
		has_fa[a] = true;//因为b为a的上司，给a的状态数组赋值为true，说明a有上司，便于之后寻找根节点
	}

	int root = 1;//令根节点为1
	while (has_fa[root]) root ++ ;//寻找根节点

	dfs(root);//通过根节点递归处理状态转移数组

	cout << max(f[root][1], f[root][0]) << endl;//输出答案

	return 0;
}