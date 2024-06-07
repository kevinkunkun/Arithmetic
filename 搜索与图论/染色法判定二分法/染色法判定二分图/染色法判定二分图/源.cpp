#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

//点与边的数据范围为100000，因为是无向图，所以边的范围扩大值两倍
const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;//邻接表数组
int color[N];//染色数组

//邻接表的插入函数
void add(int a, int b)
{
	e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

//深度有限遍历函数
bool dfs(int u, int c)
{
	color[u] = c;//让color数组中u位置染上c(也就是1，表示白色)

	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];//取出邻接表中这个点对应的插入顺序
		if (!color[j])//如果没有被染色
		{
			//递归操作，继续查与这个数相邻的下一个数，递归操作染色为黑色与白色交替染色，直到查完整条邻接表
			//递归过程中的两种终止情况：
			//情况一：这个点没有染过色，也没有返回值，将这个点染成3-c(也就是2，表示黑色),并继续检查下一个点，直至最后一个点，且与本次染色的值不同，返回true，此图为二分图
			//情况二：这个点染过色，且其染色值与本次染色的值相同，说明与二分图的本质相矛盾，返回false
			if (!dfs(j, 3 - c)) return false;
		}
		else if (color[j] == c) return false;
	}

	return true;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n >> m;

	memset(h, -1, sizeof h);//初始化邻接表头

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);//录入无向图
	}

	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		if (!color[i])//如果没有染过色
		{
			if (!dfs(i, 1))//进入dfs染色，判断是否满足二分图的性质
			{
				flag = false;//记录dfs的结果，逻辑值与dfs的相同
				break;//跳出循环，因为已经不符合二分图的性质了，无需继续循环
			}
		}
	}

	if (flag) puts("Yes");
	else puts("No");

	return 0;
}