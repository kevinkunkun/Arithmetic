#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

/*
性质：
按照顺序从1至x/i输出i，那么一定要按照倒序输出其对应的x/i才能做到从左到大的输出。
那么就非常适合使用栈来存储，利用站后进先出的性质完成倒序输出
*/
void get_divisors(int x)
{
	stack<int> s;
	for (int i = 1; i <= x / i; i++)
		if (x % i == 0)
		{
			cout << i << ' ';
			if(i!=x/i) s.push(x / i);//如果不是最后一个数，将其对应的约数压入栈中
		}
	while (s.size())
	{
		cout << s.top() << ' ';//输出栈顶
		s.pop();//弹出栈顶
	}
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
		get_divisors(x);
		cout << endl;
	}

	return 0;
}