#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5010;

int primes[N], cnt;
bool st[N];
int sum[N];

//线性筛，筛出2-n中的所有质数
void get_primes(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!st[i]) primes[cnt++] = i;
		for (int j = 0; primes[j] <= n / i; j++)
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

//将n分解为由质因数的次方之和的形式
int get(int n, int p)
{
	int res = 0;
	while (n)
	{
		res += n / p;//得到n!中存在多少个p
		n /= p;
	}
	return res;
}

//高精度乘法，计算得到一个大整数
vector<int> mul(vector<int> a, int b)
{
	vector<int> res;
	int t = 0;
	for (int i = 0; i < a.size(); i++)
	{
		t += a[i] * b;
		res.push_back(t % 10);
		t /= 10;
	}
	while (t)
	{
		res.push_back(t % 10);
		t /= 10;
	}
	return res;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	get_primes(a);//筛选2-a中的所有质数

	for (int i = 0; i < cnt; i++)
	{
		int p = primes[i];
		sum[i] = get(a, p) - get(a - b, p) - get(b, p);//利用组合数的公式，模拟得到由质因数变化的得到的公式中质数对应的指数
	}

	vector<int> res;
	res.push_back(1);//添加首元素，初始化res数组

	//第一层遍历所有质数，第二层遍历每一个质数的指数，使每一个质数乘上指数次
	for (int i = 0; i < cnt; i++)
		for (int j = 0; j < sum[i]; j++)
			res = mul(res, primes[i]);

	for (int i = res.size() - 1; i >= 0; i--) cout << res[i];//vector数组倒叙遍历输出结果
	puts("");

	return 0;
}
