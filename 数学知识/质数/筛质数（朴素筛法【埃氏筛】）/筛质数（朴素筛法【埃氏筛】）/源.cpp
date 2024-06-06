#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int n;
int primes[N], cnt;//primes���������������飬cnt����¼���������ļ�����
bool st[N];//״̬���飬��ʾ�����Ƿ�Ϊ��������Ϊfalse������Ϊtrue��

//ϣ����ѧ�Ұ�����˹���ᷢ����ɸ��������ɸ
void get_primes(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (st[i]) continue;//���Ϊ��ɾ����������������ѭ���ĺ�벿�֣�����¼������
		primes[cnt++] = i;//��ÿһ������¼������primes
		for (int j = i * 2; j <= n; j += i) st[j] = true;//��������i������������������ȫ��ɾ�������Ϊtrue��
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