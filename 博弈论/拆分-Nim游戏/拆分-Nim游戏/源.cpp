#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 110;

int f[N];//f数组用于存贮这100个点的sg函数值

int sg(int x)
{
	if (f[x] != -1) return f[x];//结束递归，是的每一个值只被计算一次

	unordered_set<int> S;//定义无序集合
	for (int i = 0; i < x; i++)//从0开始遍历至x
		for (int j = 0; j <= i; j++)//从0开始遍历至i
			S.insert(sg(i) ^ sg(j));//递归操作，直至找到i与j的sg函数值，然后插入两个值sg函数值的异或值

	//mex操作，找出不在集合中的最小正整数
	for (int i = 0;; i++)
		if (!S.count(i))
			return f[x] = i;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	memset(f, -1, sizeof f);//初始化f数组，让其等于一个不存在的正整数-1

	int n;
	cin >> n;
	int res = 0;

	while (n--)
	{
		int x;
		cin >> x;
		res ^= sg(x);
	}

	if (res) puts("Yes");
	else puts("No");

	return 0;
}