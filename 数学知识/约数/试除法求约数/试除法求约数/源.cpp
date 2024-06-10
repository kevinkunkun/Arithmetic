#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> get_divisors(int x)
{
	vector<int> res;
	for (int i = 1; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			res.push_back(i);//如果能够被整除，说明是约数，加入数组
			if (i != x / i) res.push_back(x / i);//如果不是原数字x，则将另一个约数加入数组
		}
	}
	sort(res.begin(), res.end());//对数组进行排序，最后按照从小至大的顺序输出
	return res;//返回res
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	while (n--)
	{
		int x;
		cin >> x;

		auto res = get_divisors(x);

		for (auto x : res) cout << x << ' ';//遍历方式：范围baseed for循环
		cout << endl;
	}

	return 0;
}