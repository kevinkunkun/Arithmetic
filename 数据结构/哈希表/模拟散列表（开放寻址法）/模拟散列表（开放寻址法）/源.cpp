#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

/*
①：N的值为我们寻找的大于200000的第一个质数
因为开发寻址法要开一个比我们数大两至三倍的数组空间
因为数据范围时10e5,所以选择2*10e5的大小开数组
②：在算法竞赛中为什么选择0x3f3f3f3f作为“无穷大”呢？
int类型的边界大约是2*10e9(即INT_MAX,十六进制为0x7fffffff)
0x3f3f3f3f十进制为：1061109567
此数据属于10e9的数量级，与无穷大属于统一数量级，一般的数据也都小于这个数量级
同时，0x3f3f3f3f * 2 = 2122219134小于2147483647（int的最大值），所以此“无穷大”相加也不会溢出
所以一般在算法竞赛中选择0x3f3f3f3f作为无穷大
*/
const int N = 200003, null = 0x3f3f3f3f;

int h[N];

int find(int x)
{
	int t = (x % N + N) % N;

	while (h[t] != null && h[t] != x)//如果这个数不是初始化的null且也不是我要寻找的x
	{
		t++;//跳到下一个位置
		if (t == N) t = 0;//如果判断到了最后一个位置，返回第一个位置开始寻找
	}

	return t;//如果是插入则返回找到的第一个空位置，如果是寻找则返回x所在的位置
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	memset(h, 0x3f, sizeof h);//初始化数组使得所有值都为0x3f3f3f3f

	int n;

	cin >> n;

	while (n--)
	{
		string op;
		int x;

		cin >> op >> x;
		//插入
		if (op == "I") h[find(x)] = x;
		else
		{
			//寻找
			if (h[find(x)] == null) cout << "No" << endl;
			else cout << "Yes" << endl;
		}
	}

	return 0;
}