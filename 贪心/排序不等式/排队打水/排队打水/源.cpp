#define _CRT_SECURE_NO_WARNINGS
#define fastio() cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;//人数
int t[N];//打水时间

int main()
{
	fastio();//输入输出优化

	cin >> n;//录入人数

	for (int i = 0 ; i < n; i++) cin >> t[i];//录入每人打水的时间

	sort(t, t + n);//快速排序

	/*
	将排序倒置，由贪心思想可知要让打水时间最长的人最后打水，那么在累加时，
	从0开始则需要与时间最大值匹配，而sort排序是从小到大排序的
	*/
	reverse(t, t + n);

	

	LL res = 0;//答案最大在50亿左右，而int最大为20亿，会爆int，所以用long long存储

	/*
	由贪心算法的思想可知，打水时间越长的越后打水，所以打水时间最长的应该最后打水，
	所有人都不必等待他，所以他的等待时间为0，而从0开始排序即可实现此思想
    */
	for (int i = 0; i < n; i++) res += t[i] * i;//累加答案

	cout << res << endl;//输出答案

	return 0;
}