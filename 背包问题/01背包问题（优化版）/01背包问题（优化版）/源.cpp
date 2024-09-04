#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];//优化为一维数组，f[j]表示总体积不大于j的物品的最大价值

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n >> m;//录入物品个数与背包体积

	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];//录入每个物品的体积与价值

	/*
	为什么二层循环要用降序呢?
	其实非常简单，因为我们的原等式为f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i])
	我们可以从中看出，如果我们要求新一层的值，就要用前一层的值来计算，也就是计算第i层就要用第i-1层的值
	但是如果我们降维了，没有了i来记录层数，就会导致我们会一直更新数组中同一位置的值
	如果我们还使用从小到大的顺序循环，就会一直使用以更新的值去更新下一个值
	但我们要求的时每一种情况的值，而不是在某种情况下的值，不需要前提，所以i-1层的值在使用时是不能被更新的
	如果我们倒序求值，每一次更新i+1层的值，那么我们求得的值就不会出错，因为并没有改变原公式的本质，i-1层值的内涵并没有被改变
	*/
	for(int i=1;i<=n;i++)
		for (int j = m; j >= v[i]; j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);

	cout << f[m] << endl;

	return 0;
}