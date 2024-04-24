#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N];

void dfs(int u, int state)
{
	if (u == n)//如果已经操作的位置到了n，就输出当前已经遍历到的path数组
	{
		for (int i = 0; i < n; i++) cout << path[i] << ' ';
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++)//如果已经操作的位置还没有到n
	{
		if (!(state >> i & 1))//判断state二进制中的第i位是否为0
		{
			/*
			如果为0，则让path数组的第u位加上i+1，
			因为问题式让我们从1到n进行遍历，但是我们的i是从0开始的，所以要加i+1
			*/
			path[u] = i + 1;
			/*
			递归操作，每一次传入u+1，使得u从0加一遍历到n直至遍历至最后一个元素，
			及已操作数==n时停止，并让state的第i为变为1，表示当前位置已被使用
			因为每输出一次结果后，dfs中的state都会重新定义，
			所以可以很方便的通过二进制位运算保存每一次操作中每一次递归的状态
			*/
			dfs(u + 1, state + (1 << i));
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	dfs(0,0);//从0开始操作，直至第n-1个数，到第n个数时输出；初始状态为0

	return 0;
}