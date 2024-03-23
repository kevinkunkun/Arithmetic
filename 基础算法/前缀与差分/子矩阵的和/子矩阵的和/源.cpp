#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1010;

int n, m, q;
int s[N][N];

int main()
{
	scanf("%d%d%d", &n, &m, &q);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &s[i][j]);//将所有数据，存入数组中

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];//将所有单元的前缀和通过兼容原理求出，因为s[i][j]原本存入的目标值，所以当需要使用此单元中的数时直接引用即可

	while (q--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);//通过兼容原理和之前求出的所有单元的前缀和求出任意两个单元之间数的和
	}

	return 0;
}