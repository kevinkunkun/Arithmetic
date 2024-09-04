#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//获得前l到r的数字
int get(vector<int> num, int l, int r)
{
	int res = 0;
	for (int i = l; i >= r; i--) res = res * 10 + num[i];
	return res;
}

//乘法函数，得到10的n次方
int power10(int n)
{
	int res = 1;
	for (int i = 0; i < n; i++) res *= 10;
	return res;
}

//
int count(int n, int x)
{
	vector<int> num;

	//将数字按照每一位的形式存入num中
	while (n)
	{
		num.push_back(n % 10);
		n /= 10;
	}
	n = num.size();//存储下num的长度

	int res = 0;//初始化数字x在1-n内出现的次数为0
	for (int i = n - 1 - !x; i >= 0; i--)//若x为0，则从倒数第二位开始
	{
		if (i > n - 1)
		{
			res += get(num, n - 1, i + 1) * power10(i);//第一种类型，从i+1到n-1一共有多少数字则有多少种方式，让res累加所有情况
			if (!x) res -= power10(i);//如果x为0，则需要减去之前加上了i位置上的0
		}

		if (num[i] == x) res += get(num, i - 1, 0) + 1;//第二种类型，从0到i-1一共有多少数字则有多少种方式，让res累加所有情况
		else if (num[i] > x) res += power10(i);//第三种类型，直接加上位数
	}

	return res;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//输入输出优化

	int a, b;//定义两个数
	while (cin >> a >> b, a)//如果a为0，则停止录入，达到不执行最后0 0数据的效果
	{
		if (a > b) swap(a, b);//如果a小于b，则交换a与b，因为顺序规则是从小到大

		//从0到9，逐个输出数字的个数
		for (int i = 0; i <= 9; i++)
			cout << count(b, i) - count(a - 1, i) << ' ';//输出个数采取前缀和的思想，count(a-b)则可以看成count(b)-count(a-1)
		cout << endl;
	}

	return 0;
}