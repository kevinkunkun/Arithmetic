#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 31 * N;

int a[N], son[M][2], idx;

void insert(int x)
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		/*
		&s表示给son[p][x>>i&1]取别名为s，之后s就是son[p][x>>i&1]
		x>>i&1计算出x在二进制中左移i位后的最后一位为0还是1
		*/
		int& s = son[p][x >> i & 1];
		if (!s) s = ++idx;//如果不存在此son，就创造一个新的son
		p = s;//下一次从下一行开始判断
	}
}

int serach(int x)
{
	int p = 0, res = 0;
	for (int i = 30; i >= 0; i--)
	{
		int s = x >> i & 1;
		if (son[p][!s])//判断Tire树中是否存在一个son分支同时满足与s不相同
		{
			/*
			注释①：进入此阶段，说明存在一个与s的值不同的数
			（注意：son在定义时为son[M][2],所以说s位置上只存在两种情况，不是1就是0）
			到这里，就说明s是1就找到了0；s是1就找到了0
			注释②：其次，找到了“同伴”（即1找到0，0找到1）
			就说明这两个数的二进制数在这位数上xor一定为1，即会带来异或值的增加
			这个增加的大小就是这个xor运算后那个"1"在结果二进制位数中的位置的大小
			由于我们从i=30开始直到0，这个位置其实就与i的值相等
			所以让res累加每一个"1"的2的i次方（二进制）即可计算出最终的最大异或值
			*/
			res += 1 << i;
			p = son[p][!s];//让下一次遍历从下一行开始
		}
		else
		{
			p = son[p][s];//s=1说明需要一个"0"与其异或
		}
	}

	return res;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		insert(a[i]);
	}

	int res = 0;
	//每次遍历都读出最大的异或值，取最大的一个
	for (int i = 0; i < n; i++) res = max(res, serach(a[i]));

	cout << res << endl;

	return 0;
}