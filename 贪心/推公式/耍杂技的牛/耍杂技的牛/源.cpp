#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;//数据范围

int n;//牛的数量
PII cow[N];

int main()
{
	fastio;//输入输出优化

	cin >> n;//录入牛的数量

	for (int i = 0; i < n; i++)
	{
		int w, s;
		cin >> w >> s;//录入每头牛的重量与强壮值
		cow[i] = { w + s,w };//录入结构体数组
	}

	sort(cow, cow + n);//以w+s为第一关键字，w为第二关键字进行排序

	int res = -2e9, sum = 0;//初始化危险值与总重量
	for (int i = 0; i < n; i++)
	{
		int s = cow[i].first - cow[i].second, w = cow[i].second;
		res = max(res, sum - s);//结果为此牛之上牛的总重量减去其强壮值
		sum += w;//累加总量得到新的总重量用于下一头牛的危险值计算
	}

	cout << res << endl;//输出答案

	return 0;
}