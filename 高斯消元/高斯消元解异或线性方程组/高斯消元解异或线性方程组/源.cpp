#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int a[N][N];//线性方程矩阵

int gauss()
{
	int r, c;//定义行与列
	for (r = c = 0; c < n; c++)
	{
		int t = r;//用t等于r模拟寻找这一列值为1的行
		for (int i = r; i < n; i++)
			if (a[i][c])//如果值为1
				t = i;//令t等于这一行的行数


		//如果找完了剩余的所有行，都没有一行值为1，说明此线性方程一定有无穷解或无解，跳过此循环，便于后续判断
		if (!a[t][c]) continue;

		for (int i = c; i < n + 1; i++) swap(a[t][i], a[r][i]);//将这一行与目前未处理的第一行交换

		//处理后面的每一行，将每一行的当前列值通过异或运算处理为0
		for (int i = r + 1; i < n; i++)
			if (a[i][c])//如果值不为0，说明这一行需要进行处理
				for (int j = c; j <= n; j++)//遍历这一行的每一列的元素
					a[i][j] ^= a[r][j];//进行异或运算
		r++;//让r自增，表示线性方程处理完成了一行
	}

	if (r < n)//如果处理的行数不等于总行数，说明循环中一定有次数被跳过了
	{
		for (int i = r; i < n; i++)
			if (a[i][n])//如果存在0！=0的行数，说明线性方程无解
				return 2;//返回2
		return 1;//否则有无穷解，返回1
	}

	//剩下种类一定是有唯一解，则从倒数第一行开始消元得到最终值
	for (int i = n - 1; i >= 0; i--)
		for (int j = i + 1; j < n; j++)
			a[i][n] ^= a[i][j] & a[j][n];

	return 0;//有唯一解，返回0
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n + 1; j++)
			cin >> a[i][j];//录入线性方程组

	int t = gauss();//高斯消元

	if (t == 0)
	{
		for (int i = 0; i < n; i++)
			cout << a[i][n] << endl;
	}
	else if (t == 1) puts("Multiple sets of solutions");
	else if (t == 2) puts("No solution");

	return 0;
}