#define _CRT_SECURE_NO_WARNINGS

//台阶版的NIM游戏，结论：A1^A3^A5···A(2n-1)!=0,先手必胜
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int res = 0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		if (i % 2) res ^= x;//结论：从A1、A2、A3、···An异或所有奇数台阶上的的石子数
	}

	if (res) puts("Yes");//若异或结果不为零，说明先手必胜
	else puts("No");//否则先手必败

	return 0;
}