#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;//数据范围

int n;//商店数量
int q[N];//存储商店坐标的数组

int main()
{
	fastio;//输入输出优化

	cin >> n;//录入商店数量

	for (int i = 0; i < n; i++) cin >> q[i];//录入商店坐标距离

	sort(q, q + n);//依据商店距离对商店进行排序

	int res = 0;//初始化结果
	for (int i = 0; i < n; i++) res += abs(q[i] - q[n / 2]);//由贪心思想可知，要求距离最小，则货仓一定要建立在仓库从小到大排序的中位数上

	cout << res << endl;//输出答案

	return 0;
}