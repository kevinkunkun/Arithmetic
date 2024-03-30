#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1000010;

int n, m;
int a[N], b[N];

void insert(int l,int r,int c)
{
	b[l] += c;
	b[r + 1] -= c;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++) insert(i, i, a[i]);//加入啊a数组中全为零，则执行后b数组中也全为零，此操作相当于初始化b数组，将b初始化为a数组的差分数组

	while (m--)
	{
		int l, r,c;
		scanf("%d%d%d", &l, &r, &c);
		insert(l, r, c);
	}

	for (int i = 1; i <= n; i++)
		b[i] += b[i - 1];//将b数组中的差分变为前缀和

	for (int i = 1; i <= n; i++)
		printf("%d ", b[i]);

	return 0;
}