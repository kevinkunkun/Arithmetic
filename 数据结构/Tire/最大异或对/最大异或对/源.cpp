#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 31 * N;

int a[N], son[M][2], idx;

void insert(int x)
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		/*
		&s��ʾ��son[p][x>>i&1]ȡ����Ϊs��֮��s����son[p][x>>i&1]
		x>>i&1�����x�ڶ�����������iλ������һλΪ0����1
		*/
		int& s = son[p][x >> i & 1];
		if (!s) s = ++idx;//��������ڴ�son���ʹ���һ���µ�son
		p = s;//��һ�δ���һ�п�ʼ�ж�
	}
}

int serach(int x)
{
	int p = 0, res = 0;
	for (int i = 30; i >= 0; i--)
	{
		int s = x >> i & 1;
		if (son[p][!s])//�ж�Tire�����Ƿ����һ��son��֧ͬʱ������s����ͬ
		{
			/*
			ע�͢٣�����˽׶Σ�˵������һ����s��ֵ��ͬ����
			��ע�⣺son�ڶ���ʱΪson[M][2],����˵sλ����ֻ�����������������1����0��
			�������˵��s��1���ҵ���0��s��1���ҵ���0
			ע�͢ڣ���Σ��ҵ��ˡ�ͬ�顱����1�ҵ�0��0�ҵ�1��
			��˵�����������Ķ�����������λ����xorһ��Ϊ1������������ֵ������
			������ӵĴ�С�������xor������Ǹ�"1"�ڽ��������λ���е�λ�õĴ�С
			�������Ǵ�i=30��ʼֱ��0�����λ����ʵ����i��ֵ���
			������res�ۼ�ÿһ��"1"��2��i�η��������ƣ����ɼ�������յ�������ֵ
			*/
			res += 1 << i;
			p = son[p][!s];//����һ�α�������һ�п�ʼ
		}
		else
		{
			p = son[p][s];//s=1˵����Ҫһ��"0"�������
		}
	}

	return res;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		insert(a[i]);
	}

	int res = 0;
	//ÿ�α����������������ֵ��ȡ����һ��
	for (int i = 0; i < n; i++) res = max(res, serach(a[i]));

	cout << res << endl;

	return 0;
}