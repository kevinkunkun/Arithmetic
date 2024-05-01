#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

stack<int> num;//定义一个用于存储数字的栈
stack<char> op;//定义一个用于存储字符的栈

void eval()
{
	auto b = num.top();
	num.pop();
	auto a = num.top();
	num.pop();
	auto c = op.top();
	op.pop();
	int x;
	if (c == '+') x = a + b;
	else if (c == '-') x = a - b;
	else if (c == '*') x = a * b;
	else x = a / b;
	num.push(x);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	unordered_map<char, int> pr = { {'+',1},{'-',1},{'*',2},{'/',2} };//无序映射，让+与-映射1，让*与/映射2，用于判断优先级

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		auto c = str[i];
		if (isdigit(c))//判断c是否属于0~9的整数
		{
			int x = 0, j = i;
			while (j < str.size() && isdigit(str[j]))
				x = x * 10 + str[j++] - '0';
			i = j - 1;
			num.push(x);
		}//将数字逐个压入num栈中
		else if (c == '(') op.push(c);
		else if (c == ')')
		{
			while (op.top() != '(') eval();
			op.pop();
		}//处理括号内的运算（优先级更高）
		else
		{
			while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c]) eval();//若此时还存在字符且由优先级为2且在左括号内，优先计算此段的值
			op.push(c);//将+与-符号压入op栈中
		}
	}

	while (op.size()) eval();//处理+与-的运算
	cout << num.top() << endl;

	return 0;
}