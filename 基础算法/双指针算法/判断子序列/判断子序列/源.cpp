#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (a[i] == b[j]) i++;//如果a中含有与b中相同的元素则遍历下一个a中的元素
		j++;//因为将a作为模板，所以因该遍历所有b的元素，则每一次循环都应遍历下一个b中的元素
	}

	if (i == n)
		cout << "Yes" << ' ';//若i==n说明a中等1元素被遍历完了，则a为b子序列
	else
		cout << "No" << ' ';

	return 0;
}