#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//ŷ������
int phi(int x)
{
	int res = x;
	for (int i = 2; i <= x / i; i++)
		if (x % i == 0)
		{
			//��ʽ��ŷ������=x*��(��һ��������-1)/��һ����������*��(�ڶ���������-1)/�ڶ�����������������
			res = res / i * (i - 1);//�ȳ���˱������
			while (x % i == 0) x /= i;//ȥ��x�����е�������i
		}
	if (x > 1) res = res / x * (x - 1);//������ڱ�x/i�����������������ŷ�������ļ���

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
		int x;
		cin >> x;
		cout << phi(x) << endl;
	}

	return 0;
}