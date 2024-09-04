#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 310;

int n;//石子堆数
int s[N];//前缀和数组
int f[N][N];//状态数组，f[i][j]表示从第i堆石子合并至第j堆石子所需要消耗的最小体力

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n;//录入堆数
	for (int i = 1; i <= n; i++) cin >> s[i];//录入每堆石子数

	for (int i = 1; i <= n; i++) s[i] += s[i - 1];//求出每一堆石子的前缀和

	for (int len = 2; len <= n; len++)//从第二堆开始，因为第一堆不需要合并，体力消耗为0
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int l = i, r = i + len - 1;//奖所有石子分成两堆，一堆在左边，一堆在右边，分别用l与r表示
			f[l][r] = 1e8;//初始化状态数组为一个非常大的数，便于后续取最小值，类似于初始化res=0
			for (int k = l; k < r; k++)//从左向右递推通过状态转移得到f[l][r]的最终状态
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
		}

	cout << f[1][n] << endl;//输出结果
	return 0;
}