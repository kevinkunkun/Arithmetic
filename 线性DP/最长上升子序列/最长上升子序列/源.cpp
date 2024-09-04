#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;//数据范围

int n;//序列长度
int a[N], f[N];//a为存储序列的数组;f[i]表示从第一个数到第i个数的最大上升序列的长度

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n;//录入序列长度

	for (int i = 1; i <= n; i++) cin >> a[i];//录入序列

	for (int i = 1; i <= n; i++)
	{
		f[i] = 1;//不管前面有几个数，到i一定包含自己，所以每个数组至少为1
		for (int j = 1; j < i; j++)
			if (a[j] < a[i])//从前向后递推
				f[i] = max(f[i], f[j] + 1);//每一次符合条件就加一
	}

	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res, f[i]);//从后向前计算结果

	cout << res << endl;

	return 0;
}