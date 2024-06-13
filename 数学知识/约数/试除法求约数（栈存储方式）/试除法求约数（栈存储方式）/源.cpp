#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

/*
���ʣ�
����˳���1��x/i���i����ôһ��Ҫ���յ���������Ӧ��x/i�����������󵽴�������
��ô�ͷǳ��ʺ�ʹ��ջ���洢������վ����ȳ���������ɵ������
*/
void get_divisors(int x)
{
	stack<int> s;
	for (int i = 1; i <= x / i; i++)
		if (x % i == 0)
		{
			cout << i << ' ';
			if(i!=x/i) s.push(x / i);//����������һ�����������Ӧ��Լ��ѹ��ջ��
		}
	while (s.size())
	{
		cout << s.top() << ' ';//���ջ��
		s.pop();//����ջ��
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