#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

//�������㷨
int qmi(int a, int b, int p)
{
	int res = 1 % p;//��Ϊ���ս��Ҫmod p�����Կ�����int�棬%p�Ƿ�ֹp=1ʱ����b=0,��res=0,�𰸲���
	while (b)//��b������0ʱִ��
	{
		//�м䴦��׶��п��ܻᱬint����LL����
		if (b & 1) res = (LL)res * a % p;//���������b�Ĵ��У���ʱ��⵽1����˵������a����Ҫ��
		a = a * (LL)a % p;//ÿһ�ζ�Ҫ����a����
		b >>= 1;//ÿһ������bһλ����ѭ��������ֹ
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
		int a, b, p;
		cin >> a >> b >> p;
		cout << qmi(a, b, p) << endl;
	}

	return 0;
}