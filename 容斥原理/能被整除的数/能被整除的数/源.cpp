#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 20;

int p[N];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) cin >> p[i];

	//基于二项式的数学性质，通过位运算来模拟其全部方案数
	int res = 0;//定义答案
	for (int i = 1; i < 1 << m; i++)//通过二项式定理，用2的m次方-1来表示总方案数
	{
		int t = 1, s = 0;//初始化质因数的乘积t与集合数s
		for (int j = 0; j < m; j++)//枚举m次
		{
			if (i >> j & 1)//如果二进制位上为1，说明含有此集合
			{
				if ((LL)t * p[j] > n)//如果t与此位置的质数之积大于n，说明不符合要求
				{
					t = -1;//令t=-1
					break;//结束循环
				}

				t *= p[j];//如果符合要求，更新t的值
				s++;//更新s的值
			}
		}

		if (t != -1)//如果t符合要求，则计算最终值
		{
			if (s % 2) res += n / t;//如果s是奇数，依据容斥原理公式，应该加上此集合交集的结果
			else res -= n / t;//否则为偶数，依据公式减去集合交集的结果
		}
	}

	cout << res << endl;

	return 0;
}