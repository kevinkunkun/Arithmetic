#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1010;

int n, m, q;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c)//二维矩阵的插入函数
{
	b[x1][y1] += c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y1] -= c;
	b[x2 + 1][y2 + 1] += c;
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			insert(i, j, i, j, a[i][j]);//初始化差分矩阵b，即构造b矩阵使得a矩阵为b矩阵的前缀和

	while (q--)
	{
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);//读入q个询问，使得每一个询问的值都插入b矩阵中
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", b[i][j]);
		cout << endl;
	}

	return 0;
}