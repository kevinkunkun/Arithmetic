#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (a[i] == b[j]) i++;//���a�к�����b����ͬ��Ԫ���������һ��a�е�Ԫ��
		j++;//��Ϊ��a��Ϊģ�壬������ñ�������b��Ԫ�أ���ÿһ��ѭ����Ӧ������һ��b�е�Ԫ��
	}

	if (i == n)
		cout << "Yes" << ' ';//��i==n˵��a�е�1Ԫ�ر��������ˣ���aΪb������
	else
		cout << "No" << ' ';

	return 0;
}