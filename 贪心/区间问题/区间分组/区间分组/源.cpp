#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;//数据范围

int n;//区间数

//区间左右端点结构体
struct Range
{
	int l, r;
	bool operator<(const Range& W)const
	{
		return l < W.l;
	}
}range[N];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n;//录入区间数
	for (int i = 0; i < n; i++)
	{
		int a, b;//左右端点
		cin >> a >> b;//录入左右端点
		range[i] = { a,b };//将左右端点存入结构体
	}

	sort(range, range + n);//对所有区间根据左端点的值进行从小到达的快速排序

	priority_queue<int, vector<int>, greater<int>> heap;//定义一个小根堆

	//循环遍历每一个区间
	for (int i = 0; i < n; i++)
	{
		auto r = range[i];//获取当前区间
		if (heap.empty() || heap.top() >= r.l) heap.push(r.r);//如果当前区间的左端点小于等于其他组内最大右端点的最小值，说明要开新组，存储此区间
		else
		{
			heap.pop();//否则说明可以放入第一组中，其右端点肯定增加，所以删除原右端点
			heap.push(r.r);//将此右端点加入堆中，更新最大右端点的值
		}
	}

	cout << heap.size() << endl;//输出答案

	return 0;
}