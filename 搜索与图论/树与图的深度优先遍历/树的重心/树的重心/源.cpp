#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 2 * N;//创建N个链表，每个链表可以装入2*N个数

int n;
int h[N], e[M], ne[M], idx;//链表头节点N个，值与指针2*N个
bool st[N];//每个链表对应一个状态，共开N个来容纳每个链表的使用状态
int ans = N;//初始化ans为连通块的最大值N

//插入函数
void add(int a, int b)
{
	e[idx] = b;//将b的值存入idx节点中
	ne[idx] = h[a];//将idx节点指向a的头节点所指向的节点
	h[a] = idx++;//让头节点指向idx节点，并让idx自增（开辟新空间方便下一次插入）
}

//深度优先搜索函数
int dfs(int u)
{
	st[u] = true;//将u节点赋值为已使用节点，下一次递归操作将跳过u节点


	int size = 0, sum = 0;//初始化
	//size表示u节点的子节点中含有最多连通块的一条中的节点个数
	//sum表示u节点的所有子节点所在的连通块中的节点总个数
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];//让j等于遍历时此链表中的头节点
		if (st[j]) continue;//如果此节点已遍历过，则跳过此节点
		int s = dfs(j);//从此节点开始递归，直至找到最后一个节点
		/*
		在递归过程中不断更新节点个数，
		每一次取更大的值作为最新值，直至递归结束
		s表示的是每一此递归时的节点作父节点时其子节点所在的连通块中节点的个数
		*/
		size = max(size, s);
		sum += s;//累加每一次递归处理的s的值，得到u节点的子节点中连通块中的所有节点个数
	}

	size = max(size, n - sum - 1);
	//将得到的子节点连通块的最大值与u的父节点所处的连通块中的节点个数比较，取得最大值，最终得到的size表示若去掉u节点则剩余的节点形成的最大的连通块的值
	ans = min(ans, size);//最后将得到的值与ans的值比较取最小值，得到去掉u后得到最小连通块的值

	return sum + 1;
	/*
	返回u本身和其所有子节点的连通块中节点数之和，
	便于递归时的计算s的值，因为递归是先寻找到最后一个，
	得到返回值结果在逐步向上返回，
	那么要完成返回得到正确结果的基本要求是：
	每一个节点的子节点的连通块中的节点数解药不断返回此节点作为父节点时其所有连通块中的节点数，
	不断累加和取最大值才能得到最终结果
	*/
}
int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	memset(h, -1, sizeof h);//初始化h数组，将所有头节点都指向-1（即尾节点）

	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
		/*
		a与b的联通需要一条边，而一条边在dfs中需要看成两条有向边，
		（这也是为什么e[]与ne[]数组要开2*N的原因，有N条边，即N个以'a'为头节点的链表）
		dfs深度搜索是通过递归操作，不仅含有查找操作还含有回溯操作，因此不难理解，
		这两条有向边有一条用于深度查找而另一条则用于在查找到最后一个节点时进行回溯造作
		*/
	}

	dfs(1);//从任意一个节点都可进行完整的搜索，可以是1~n中的任意一个数

	cout << ans << ' ';

	return 0;
}