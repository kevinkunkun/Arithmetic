#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c)
{
	b[l] += c;
	b[r + 1] -= c;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), insert(i, i, a[i]);
	while (m--)
	{
		int l, r, c;
		cin >> l >> r >> c;
		insert(l, r, c);
	}
	for (int i = 1; i <= n; i++) a[i] = a[i - 1] + b[i], printf("%d ", a[i]);

	return 0;
}