#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], cnt;

void down(int x)
{
	int t = x;//初始化t（t的含义为一个最简单的二叉树中的三个数中的最小值在数组中的位置）
	/*
	判断一个最简单的二叉树中的左儿子是否存在，
	若存在，再判断左儿子与数组中发生改变处的值的大小，
	并将小的数的坐标赋给t
	*/
	if (x * 2 <= cnt && h[x * 2] < h[t]) t = x * 2;
	/*
	判断一个最简单的二叉树中的右儿子是否存在，
	若存在，再判断右儿子与数组中发生改变处的值的大小，
	并将小的数的坐标赋给t
	*/
	if (x * 2 + 1 <= cnt && h[x * 2 + 1] < h[t]) t = x * 2 + 1;
	if (x != t)//若x与t不相等，说明发生过位置的变化
	{
		swap(h[x], h[t]);//将x与t的位置交换，将最小值向上移动
		down(t);//递归处理最小值，直到将整个二叉树全部重新排序
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> h[i];
	cnt = n;

	/*
	含义是从整个二叉树的倒数第二行开始down，
	因为二叉树每多一个完整的行，相当于将原来的容量扩充至两倍，
	所以取n/2即可从倒数第二行的最后一个元素开始遍历
	因为在down函数中存在判断其是否存在子左（右）儿子，而最后一行没有左（右）儿子。
	所以直接从倒数第二行可以实现优化这一没有用的操作
	时间复杂度为O（n）
	*/
	for (int i = n / 2; i; i--) down(i);
	while (m--)
	{
		cout << h[1] << ' ';
		h[1] = h[cnt--];
		down(1);
	}

	return 0;
}