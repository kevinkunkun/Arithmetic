#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int lowbit(int x)
{
	return x & -x;//ʵ�ַ���x�������е����һ��1 x&-x=x&(~x+1)��ȡ����һ������������Բ��������ʽ����
}//��һ�ַ�ʽ��x>>k&1,������������Ƶ�kλ��1����0

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x, res = 0;;
		cin >> x;
		while (x) x -= lowbit(x), res++;//ÿ����һ��1ʹres��1��ʵ�ּ�¼1�ĸ���
		cout << res << ' ';
	}

	return 0;
}