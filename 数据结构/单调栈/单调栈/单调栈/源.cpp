#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int stk[N],tt;//Ĭ��ttΪ0����stk����ģ��ջ

int main()
{
	cin.tie(0);//�����ÿ�����cin����ʱ��ֹˢ��cout���������Լӿ���������ٶ�
	ios::sync_with_stdio(false);//�����ÿ���C++�е�iostream������������׼�������ͬ����ͬ�����Լӿ���������ٶ�
	cin >> n;

	while (n--)
	{
		int x;
		cin >> x;
		while (tt && stk[tt] >= x) tt--;//���tt������0��stk����ջ��������x��˵��������ʹ�õ���������ʹ��tt�Լ���ɾ��ջ������
		if (!tt) cout << -1 << ' ';
		else cout << stk[tt] << ' ';
		stk[++tt] = x;//�����ȷ��ֵx¼����stk������
	}

	return 0;
}