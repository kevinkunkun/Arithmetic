#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m, x;
int a[N], b[N];

int main()
{
	//输入输出速度优化
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> x;

	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < m; i++) cin >> b[i];
	//双指针优化，时间复杂度由O（n*m）变为O(n+m)，只适合于有唯一解的数据
	for (int i = 0, j = m - 1; i < n; i++)
	{
		while (j >= 0 && a[i] + b[j] > x) j--;
		if (j >= 0 && a[i] + b[j] == x) cout << i << ' ' << j << endl;
	}

	return 0;
}
