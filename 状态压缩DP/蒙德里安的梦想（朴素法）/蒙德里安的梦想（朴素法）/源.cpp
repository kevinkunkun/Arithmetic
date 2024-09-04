#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 12, M = 1 << N;//数据范围

int n, m;//行数与列数
long long  f[N][M];//状态转移数组
bool st[M];//状态数组

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	while (cin >> n >> m, n)//达到当最后一行为0时，停止输入，不做运算的目的
	{
		//处理状态数组st，处理出横向放置时的特判条件
		for (int i = 0; i < 1 << n; i++)
		{
			int cnt = 0;
			st[i] = true;

			for (int j = 0; j < n; j++)
				if (i >> j & 1)//如果为1，说明到了一个新的1，判断两个1之间0的个数
				{
					if (cnt & 1) st[i] = false;//如果个数为奇数，st状态赋值为false
					cnt = 0;//重置cnt为偶数
				}
				else cnt++;//如果为0，则自增，计算0的个数
			if (cnt & 1) st[i] = false;//判断最后一段种0的个数
		}

		memset(f, 0, sizeof f);//初始化f数组为0
		f[0][0] = 1;//递归基
		for (int i = 1; i <= m; i++)
			for (int j = 0; j < 1 << n; j++)
				for (int k = 0; k < 1 << n; k++)
					if ((j & k) == 0 && st[j | k])//满足特判条件则横向装填
						f[i][j] += f[i - 1][k];//累加所有的情况

		cout << f[m][0] << endl;//输出答案
	}

	return 0;
}