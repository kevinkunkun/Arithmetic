#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

//ŷ������㷨
int gcd(int a, int b)
{
	//��ʽ��gcd(a,b)=gcd(a,a%b)
	return b ? gcd(b, a % b) : a;//���b��Ϊ�㣬��ݹ鴦���൱��շת������е�շת����ֱ��b����0����ʱ��a��Ϊ���Լ��
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//��������Ż�

	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << gcd(a, b) << endl;
	}

	return 0;
}