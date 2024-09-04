#define _CRT_SECURE_NO_WARNINGS

//本算法适用于使用集合处理的NIM游戏，本算法以选石子游戏为例
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 110, M = 10010;//每一次拿取的值在0~100以内，每一堆石子的个数在0~10000以内

int n, m;
int f[M], s[N];//f数组用于存放每一堆石子（对应的那张图）的首节点的sg函数值，s数组用于存放每一次能够拿取石子的个数

//获取每一堆石子进行拿取的图中每一个节点的sg函数值
int sg(int x)
{
	//记忆化搜索
	//只要最终的f[x]不为初始值-1，则返回f[x]的值，保证每一个值只计算一次
	if (f[x] != -1) return f[x];

	//递归处理得到全部图中每一次拿取的sg函数值
	//处理每一堆石子，得到这对石子对应的图的首节点的sg值
	unordered_set<int> S;//定义一个无序集合
	for (int i = 0; i < m; i++)//遍历每一次能够拿取石子的数值
	{
		int sum = s[i];//取得本次能够取出的数值
		if (x >= sum) S.insert(sg(x - sum));//如果能够继续取出，那么就一直递归处理直至最后一层
	}

	//mex运算的最后一步，从0开始筛选一个最小的不在集合中的正整数
	for (int i = 0;; i++)
		if (!S.count(i))
			return f[x] = i;//如果此位置的集合中没有值，则让f[x]等于i并返回
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> m;
	for (int i = 0; i < m; i++) cin >> s[i];

	cin >> n;

	memset(f, -1, sizeof f);//初始化f数组

	int res = 0;//初始化res为0，0与任何值x进行异或运算结果都为x
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;//读入每一堆石子的个数

		/*
		每一对石子对应一张图，此时计算这张图的所有情况的sg函数值，
		并通过mex函数计算出最初的sg函数值。
		最后再将每一次的sg函数值进行异或运算得到最终值
		*/
		res ^= sg(x);
	}

	if (res) puts("Yes");//如果结果不为零，根据Nim定理，说明先手必胜
	else puts("No");//否则先手必败

	return 0;
}