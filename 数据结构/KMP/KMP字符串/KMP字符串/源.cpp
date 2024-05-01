#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];
char s[M], q[N];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> q + 1 >> m >> s + 1;
	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j && q[i] != q[j + 1]) j = ne[j];
		if (q[i] == q[j + 1]) j++;
		ne[i] = j;
	}

	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j && s[i] != q[j + 1]) j = ne[j];
		if (s[i] == q[j + 1]) j++;
		if (j == n)
		{
			cout << i - n << ' ';
			j = ne[j];
		}
	}

	return 0;
}
