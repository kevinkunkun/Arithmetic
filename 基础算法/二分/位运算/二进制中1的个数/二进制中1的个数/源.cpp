#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int lowbit(int x)
{
	return x & -x;//实现返回x二级制中的最后一个1 x&-x=x&(~x+1)即取反加一，计算机里数以补码的行形式储存
}//另一种方式是x>>k&1,可以算出二进制第k位是1或是0

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x, res = 0;;
		cin >> x;
		while (x) x -= lowbit(x), res++;//每返回一次1使res加1，实现记录1的个数
		cout << res << ' ';
	}

	return 0;
}