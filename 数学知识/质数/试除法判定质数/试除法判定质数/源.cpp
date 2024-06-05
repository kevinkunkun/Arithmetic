#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int n;

bool is_prime(int x)
{
	if (x < 2) return false;//���С��2���϶���������

	//Q1:Ϊʲôʹ��x/i?
	//A1:��Ϊ���һ����������������ô��һ�����������ӣ�����ÿһ��ֻ��Ҫ��������С����һ��������
	//Q2:Ϊʲô������sqrt(i)?
	//A2:��Ϊsqrt()��һ��������ѭ��ÿ�ε����˷�ʱ��
	//Q3:Ϊʲô��ʹ��i*i<x?
	//A3:��Ϊ�����ݽӽ���int�����ֵʱ����������ķ��գ��������ݱ�Ϊ����
	for (int i = 2; i <= x / i; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;

	while (n--)
	{
		int x;
		cin >> x;
		if (is_prime(x)) puts("Yes");
		else puts("No");
	}

	return 0;
}