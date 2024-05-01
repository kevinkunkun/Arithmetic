#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1000010;

int n, k;
int a[N], q[N];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int hh = 0, tt = -1;//��ʼ��hh��tt��hhΪ��ͷ��ttΪ��β��

	//��ÿ�����ڵ���Сֵ
	for (int i = 0; i < n; i++)
	{
		if (hh <= tt && i - k + 1 > q[hh]) hh++;//��q�е�������k���ƶ����ƶ���ʹ��q�е�λ������ʼ��ָ��k�����е�λ������

		while (hh <= tt && a[q[tt]] >= a[i]) tt--;//����ǰ��β�����Ӧ����ֵ���ڱ�������������˵���˶�β������ԶҲ�����õ�������βɾ��
		q[++tt] = i;//�ٽ������������β

		if (i >= k - 1) cout << a[q[hh]] << ' ';//�������������ڴ�����������������㷨��������������
	}
	cout << endl;

	//��ÿ�����ڵ����ֵ����Ѱ����Сֵͬ��
	hh = 0, tt = -1;
	for (int i = 0; i < n; i++)
	{
		if (hh <= tt && i - k + 1 > q[hh]) hh++;

		while (hh <= tt && a[q[tt]] <= a[i]) tt--;
		q[++tt] = i;

		if (i >= k - 1) cout << a[q[hh]] << ' ';
	}
	cout << endl;

	return 0;
}