#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int n;

//�ֽ�����������
void divide(int x)
{
	//Q1:ʲô�Ƿֽ���������ʲô���������ĵ�����ָ����
	/*
	A1:һ������������������������Էֽ��Ϊ����С������
	����12=2*2*3����ô2��3����12����������Ҳ���ǵ���������2���������Σ���ô����2��ָ������2
	*/
	//Q2:ΪʲôҪ��2��ʼ��������x/i�أ�
	/*
	A2:��ΪҪ����������������ôһ��Ҫ��2��ʼ����Ϊn��ֻ����һ������sqrt(n)����������
	����ֻ��Ҫ������sqrt(n)���ɣ��������������һ���������������ɡ�
	����Ϊʲôʹ��x/i������sqrt()��������Ϊsqrt()������
	*/
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			int s = 0;
			while (x % i == 0) x /= i, s++;
			cout << i << ' ' << s << endl;
		}
	}

	//�����������һ���������������x����1��˵����û���������ͳ�ѭ���ˣ���ʾ�����������
	if (x > 1) cout << x << ' ' << 1 << endl;
	cout << endl;
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
		divide(x);
	}

	return 0;
}