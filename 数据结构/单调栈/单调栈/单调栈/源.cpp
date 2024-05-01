#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int stk[N],tt;//默认tt为0，用stk数组模拟栈

int main()
{
	cin.tie(0);//此设置可以在cin输入时禁止刷新cout缓冲区，以加快输入输出速度
	ios::sync_with_stdio(false);//此设置可以C++中得iostream输入输出不与标准输入输出同步，同样可以加快输入输出速度
	cin >> n;

	while (n--)
	{
		int x;
		cin >> x;
		while (tt && stk[tt] >= x) tt--;//如果tt不等于0且stk数组栈顶数大于x，说明不会再使用到此数，即使得tt自减，删除栈顶的数
		if (!tt) cout << -1 << ' ';
		else cout << stk[tt] << ' ';
		stk[++tt] = x;//最后将正确的值x录入至stk数组中
	}

	return 0;
}