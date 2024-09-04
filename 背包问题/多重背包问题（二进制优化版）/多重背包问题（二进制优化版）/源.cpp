#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 12010, M = 2010;

int n, m;
int v[N], w[N];
int f[M];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	/*
	采用二进制的方式，将多重背包化简为k个2的次方的背包，
	每一个背包只用使用一次来表示原背包里物品的个数，
	可将时间复杂度从O(n*m*k)简化至O(n*m*logn)
	*/ 

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int a, b, s;
		cin >> a >> b >> s;//录入每一个物品的体积、价值、个数
		int k = 1;//初始化k为1(2的0次方)
		while (k <= s)//当k<=s时，将每一个物品的格式拆分为二进制
		{
			cnt++;//开辟新的位置用于存放物品体积、价值的更新值
			v[cnt] = a * k;//用当前k的值更新体积
			w[cnt] = b * k;//用当前k的值更新价值
			s -= k;//更新完后将已更新的个数从总个数中减去
			k *= 2;//k以二进制倍数增长
		}
		if (s > 0)//如果更新完后s不为0，说明还存在一个余数，此数大于2的k次方，小于2的k+1次方
		{
			cnt++;//开辟新的位置用于存放物品体积、价值的更新值
			v[cnt] = a * s;//用直接用剩下的s的值更新体积
			w[cnt] = b * s;//用直接用剩下的s的值更新价值
		}
	}

	// 二进制转换后，现在的已变成cnt个物品的01背包问题

	n = cnt;//将n的值变为cnt

	//优化版的01背包问题算法
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= v[i]; j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);

	cout << f[m] << endl;

	return 0;
}