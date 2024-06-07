#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int n;
int primes[N], cnt;//peimes:�������飻cnt:����������
bool st[N];//״̬���飬trueΪ����������falseΪ������

//����ɸ��
void get_primes(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!st[i]) primes[cnt++] = i;//��������������������������
		for (int j = 0; primes[j] <= n / i; j++)
		{
			st[primes[j] * i] = true;//��������������С������2С��ʼ������ɾ������i�ĳ˻��������

			//���primes��ĳһ�����ܹ�����i���򼰽����˴�ѭ�����������ɾ����һ��������i�˻���ֱ��������Ϊi����С������
			if (i % primes[j] == 0) break;
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;

	get_primes(n);

	cout << cnt << endl;

	return 0;
}