#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;//数据范围

int n;//小区间个数
int st, ed;//大区间范围

//存储小区间左右端点的结构体
struct Range
{
	int l, r;
	bool operator<(const Range& W)const
	{
		return l < W.l;//返回左端点的最小值
	}
}range[N];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> st >> ed;//录入大区间
	cin >> n;//录入小区间个数

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		range[i] = { a,b };//录入小区间的左右端点
	}

	sort(range, range + n);//依据左端点的大小对小区间从小到大排序

	int res = 0;//初始化res=0
	bool success = false;//初始化状态表示success为false
	for (int i = 0; i < n; i++)
	{
		int j = i, r = -2e9;//初始化双指针j与比较的中间量r
		while (j < n && range[j].l <= st)//如果此区间没有超出总区间范围且其左端点比大区间的左端点小
		{
			r = max(r, range[j].r);//遍历取得最大的右端点
			j++;//j自增，直至找到最大的右端点
		}

		if (r < st)//如果找到了最大右端点但是右端点都不能包含大区间的左端点，说明无解
		{
			res = -1;//令res=-1
			break;//结束循环
		}

		res++;//否则说明此区间是正解，res自增
		if (r >= ed)//如果此时的r比大区间的右端点还大，说明大区间已经被完全包围
		{
			success = true;//令状态表示为true，说明求解完毕
			break;//结束循环
		}

		st = r;//令大区间的左端点为此区间的右端点，因为这一段距离已经被包含了，下一次遍历从此右端点开始判断
		i = j - 1;//令指针i指向指针j-1的位置，因为此位置是第一个正解的位置
	}

	if (!success) res = -1;//如果没有完毕，令res=-1(题目要求)

	cout << res << endl;//输出答案

	return 0;
}