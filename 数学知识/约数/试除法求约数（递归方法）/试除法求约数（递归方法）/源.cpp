#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void get_divisors(int x,int i)
{
	if (i > x / i) return;//���������Ϊ��С��Լ���Ѿ����ڴ��Լ����������һ��

	if (x % i == 0) cout << i << ' ';//�������Լ����Ҫ���������Լ��

	get_divisors(x,i + 1);//�ݹ������ֱ��СԼ�����ڴ��Լ��

	/*
	����һ����˵��С��Լ���Ѿ������
	�ݹ鿪ʼ���أ������СԼ���е�����һ����ʼ���أ��õ���x/i��������С�ģ������Ǵ�С�����˳��
	*/
	if (x % i == 0 && i != x / i) cout << x / i << ' ';
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
		get_divisors(x,1);//��1��ʼ�ݹ飬�൱��forѭ���е�i=1
		cout << endl;
	}

	return 0;
}