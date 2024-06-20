#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

//�������㷨
int qmi(int a, int b, int p)
{
	LL res = 1;
	while (b)
	{
		if (b & 1) res = res * a % p;
		a = a * (LL)a % p;
		b >>= 1;
	}
	return res;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	while (n--)
	{
		int a, p;
		cin >> a >> p;
		if (a % p == 0) cout << "impossible" << endl;//���a��p�ı��������ݷ���С�����֪��������Ԫ
		else cout << qmi(a, p - 2, p) << endl;//���a����p�ı��������ݷ���С��������Ԫ�Ķ���ͨ���������㷨�����
	}

	return 0;
}