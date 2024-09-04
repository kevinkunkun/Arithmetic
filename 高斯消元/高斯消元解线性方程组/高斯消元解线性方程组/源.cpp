#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-8;//规定一个判断浮点数是否为0的小数

int n;
double a[N][N];//n*(n+1)的矩阵

int gauss()
{
	int r, c;//r表示每一次遍历时的第一行，c表示列数
	for (r = 0, c = 0; c < n; c++)
	{
		int t = r;//取t为r，去剩余的行列式中寻找此列中值最大的一行
		for (int i = r; i < n; i++)
			if (fabs(a[i][c]) > fabs(a[t][c]))//fabs()用于返回浮点数的绝对值
				t = i;//找到值大的便赋值给t

		if (fabs(a[t][c]) < eps) continue;//如果找到的最大行是0，说明不存在唯一解，跳过此循环

		for (int i = c; i < n + 1; i++) swap(a[t][i], a[r][i]);//把找到的t对应的哪一行全部交换至未确定的行列式中的第一行
		for (int i = n; i >= c; i--) a[r][i] /= a[r][c];//让交换后的第一行对应的这一列的系数变为一，其他列的系数也随之变化

		//接着通过这一行的值进行初等变换，将后面的所有行的这一列的数值变为0
		for (int i = r + 1; i < n; i++)
		{
			if (fabs(a[i][c]) > eps)//如果这一行对应的值不为0，说明要进行初等变换
				for (int j = n; j >= 0; j--)
					a[i][j] -= a[r][j] * a[i][c];
		}
		r++;//让r+1，说明已经处理完一行与一列的值了
	}

	if (r < n)//第一个for循环结束的条件为c<n，如果此时r<n说明循环中有次数一定被跳过了，一定不存在唯一解
	{
		for (int i = r; i < n; i++)
			if (fabs(a[i][n]) > eps)//如果存在0！=0等等式，说明无解
				return 2;//
		return 1;//否则一定是0=0的形式，有无数解
	}

	//最后进行对处理好的行列式倒着处理结果，获得最后需要的值
	for (int i = n - 1; i >= 0; i--)
		for (int j = i + 1; j < n; j++)
			a[i][n] -= a[j][n] * a[i][j];

	return 0;//存在唯一解，返回0
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n + 1; j++)
			scanf("%lf", &a[i][j]);//录入n*(n+1)的行列式

	int t = gauss();//进行高斯消元，返回三种结果之一

	if (t == 1) puts("Infinite group solutions");//如果返回1，说明存在无数解
	else if (t == 2) puts("No solution");//如果返回2，说明无解
	else
	{
		for (int i = 0; i < n; i++)
			printf("%.2lf\n", a[i][n]);//否则存在唯一解，按行逐个输出
	}

	return 0;
}