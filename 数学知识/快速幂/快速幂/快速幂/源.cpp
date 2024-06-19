#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

//快速幂算法
int qmi(int a, int b, int p)
{
	int res = 1 % p;//因为最终结果要mod p，所以可以用int存，%p是防止p=1时，若b=0,则res=0,答案不符
	while (b)//当b不等于0时执行
	{
		//中间处理阶段有可能会爆int，用LL处理
		if (b & 1) res = (LL)res * a % p;//如果二进制b的串中，此时检测到1，则说明存在a的幂要乘
		a = a * (LL)a % p;//每一次都要更新a的幂
		b >>= 1;//每一次右移b一位，让循环可以终止
	}
	return res;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	while (n--)
	{
		int a, b, p;
		cin >> a >> b >> p;
		cout << qmi(a, b, p) << endl;
	}

	return 0;
}