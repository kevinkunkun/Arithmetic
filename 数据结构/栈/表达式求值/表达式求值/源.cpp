#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

stack<int> num;//����һ�����ڴ洢���ֵ�ջ
stack<char> op;//����һ�����ڴ洢�ַ���ջ

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

	unordered_map<char, int> pr = { {'+',1},{'-',1},{'*',2},{'/',2} };//����ӳ�䣬��+��-ӳ��1����*��/ӳ��2�������ж����ȼ�

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		auto c = str[i];
		if (isdigit(c))//�ж�c�Ƿ�����0~9������
		{
			int x = 0, j = i;
			while (j < str.size() && isdigit(str[j]))
				x = x * 10 + str[j++] - '0';
			i = j - 1;
			num.push(x);
		}//���������ѹ��numջ��
		else if (c == '(') op.push(c);
		else if (c == ')')
		{
			while (op.top() != '(') eval();
			op.pop();
		}//���������ڵ����㣨���ȼ����ߣ�
		else
		{
			while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c]) eval();//����ʱ�������ַ��������ȼ�Ϊ2�����������ڣ����ȼ���˶ε�ֵ
			op.push(c);//��+��-����ѹ��opջ��
		}
	}

	while (op.size()) eval();//����+��-������
	cout << num.top() << endl;

	return 0;
}