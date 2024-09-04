#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;//数据范围

int n;//数字个数
int a[N];//存储数字的数组
int q[N];//存储最大上升子序列的数组

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n;//录入数字个数
	for (int i = 0; i < n; i++) cin >> a[i];//录入每个数字

	int len = 0;//初始化q的长度为0
	for (int i = 0; i < n; i++)
	{
		//二分查找
		int l = 0, r = len;//初始化左端点为0，右端点为len，表示在q数组的两端
		while (l < r)
		{
			int mid = l + r + 1 >> 1;//因为判断条件为l=mid，二分模板为l+r+1>>1
			if (q[mid] < a[i]) l = mid;//进行端点的变化，二分查找小于r的最大数字
			else r = mid - 1;
		}
		len = max(len, r + 1);//找到数字后进行答案的更新，如果找到后的数字加一比原len大，说明序列长度得到加长，为长度更新长度len的值
		q[r + 1] = a[i];//数字填入将找到的位置上
	}

	cout << len << endl;//输出答案

	return 0;

}