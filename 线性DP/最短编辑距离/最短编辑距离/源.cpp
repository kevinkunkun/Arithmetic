#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;//字符串长度
char a[N], b[N];//存储字符串字符的数组
int f[N][N];//状态转移数组

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	cin >> n >> a + 1;//录入字符串a的字符数与字符
	cin >> m >> b + 1;//录入字符串b的字符数与字符

	for (int i = 0; i <= m; i++) f[0][i] = i;//初始化状态转移数组f[i][j],当a长度为0时，说明要将a变为b需要进行i次增加操作
	for (int i = 0; i <= n; i++) f[i][0] = i;//初始化状态转移数组f[i][j],当b长度为0时，说明要将a变为b需要进行i次删除操作

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);//模拟操作一与操作二，每次取最小值
			if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);//模拟操作三，每次取最小值
			else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
		}

	cout << f[n][m] << endl;//输出结果

	return 0;
}