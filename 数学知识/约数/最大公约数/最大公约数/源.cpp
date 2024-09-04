#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

//欧几里得算法
int gcd(int a, int b)
{
	//公式：gcd(a,b)=gcd(a,a%b)
	return b ? gcd(b, a % b) : a;//如果b不为零，则递归处理（相当于辗转相除法中的辗转），直至b等于0，此时的a即为最大公约数
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << gcd(a, b) << endl;
	}

	return 0;
}