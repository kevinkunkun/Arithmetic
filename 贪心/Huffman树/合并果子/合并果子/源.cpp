#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;//果子数量

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n;//录入果子堆数
	priority_queue<int, vector<int>, greater<int>> heap;//定义一个小根堆

	//遍历录入每一堆的果子个数
	while (n--)
	{
		int x;
		cin >> x;
		heap.push(x);//将得到的数量加入堆中
	}

	int res = 0;//初始化答案为0
	while (heap.size()>1)//因为最后要合并成一堆果子，所以堆的长度应该大于1
	{
		int a, b;//定义两个节点
		a = heap.top(), heap.pop();//让a等于最小值，并在堆中弹出此最小值
		b = heap.top(), heap.pop();//让b等于次小值，并在堆中弹出此次小值
		res += a + b;//累加两值，含义为合并两堆果子
		heap.push(a + b);//将合并后的果子加入堆
	}

	cout << res << endl;//输出结果

	return 0;
}