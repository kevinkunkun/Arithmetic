#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 15, M = 1010;//数据范围

int n, m;//字符串数与询问数
int f[N][N];//状态数组
char str[M][N];//字符数组

//编辑距离函数
int edit_distance(char a[], char b[])
{
	int la = strlen(a + 1), lb = strlen(b + 1);//得到传入的两个字符串的长度

	for (int i = 0; i <= lb; i++) f[0][i] = i;//处理字符串a为0的边界问题
	for (int i = 0; i <= la; i++) f[i][0] = i;//处理字符串b为0的边界问题

	//状态转移
	for (int i = 1; i <= la; i++)
		for (int j = 1; j <= lb; j++)
		{
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);//模拟操作一与操作二
			f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));//模拟操作三
		}

	return f[la][lb];//返回匹配次数
}

int mian()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;//录入字符串个数与询问次数

	for (int i = 0; i < n; i++) cin >> str[i] + 1;//；录入字符串a

	//循环录入询问，并输出答案
	while (m--)
	{
		char s[N];
		int limit;
		int res = 0;

		cin >> s + 1 >> limit;//录入字符串b与最大次数

		//循环n次，调用编辑次数函数进行判断，输出答案
		for (int i = 0; i < n; i++)
			if (edit_distance(str[i], s) <= limit)
				res++;

		cout << res << endl;
	}

	return 0;
}