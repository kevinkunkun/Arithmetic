#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;//字符串A的长度与字符串B的长度
char a[N], b[N];//存储两个字符串中所有字符的数组
int f[N][N];//状态数组，f[i][j]表示在A字符串中的前i个字符出现，且在字符串B中的前j个字符出现的字符组合的字符最大值

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n >> m;
	cin >> a + 1 >> b + 1;

	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++)
		{
			/*
			//将三种类型用同一状态转移方程表示
			（0表示不包含a[i](b[j]),1表示包含a[i](b[j])）
			00类型包含在01与10类型中，所以可以只表示01、10和11类型
			01包含在f[i-1][j]中，10类型包含在f[i][j-1]类型中，但使用f[i-1][j]与f[i][j-1]会导致重复计算
			因为求题目要求最大值，所以允许重复
			*/
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
		}

	cout << f[n][m] << endl;//输出结果

	return 0;
}