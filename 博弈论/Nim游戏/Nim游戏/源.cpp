#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int res=0;//初始化res为0，0与x异或等于x
	int n;
	cin >> n;

	while (n--)
	{
		int x;
		cin >> x;
		res ^= x;//让res与每一个x进行异或运算
	}

	if (res) puts("Yes");//如果不为0，说明先手必胜
	else puts("No");//否则先手必败

	return 0;
}