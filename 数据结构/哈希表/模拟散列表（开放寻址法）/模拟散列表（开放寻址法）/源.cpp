#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

/*
�٣�N��ֵΪ����Ѱ�ҵĴ���200000�ĵ�һ������
��Ϊ����Ѱַ��Ҫ��һ��������������������������ռ�
��Ϊ���ݷ�Χʱ10e5,����ѡ��2*10e5�Ĵ�С������
�ڣ����㷨������Ϊʲôѡ��0x3f3f3f3f��Ϊ��������أ�
int���͵ı߽��Լ��2*10e9(��INT_MAX,ʮ������Ϊ0x7fffffff)
0x3f3f3f3fʮ����Ϊ��1061109567
����������10e9���������������������ͳһ��������һ�������Ҳ��С�����������
ͬʱ��0x3f3f3f3f * 2 = 2122219134С��2147483647��int�����ֵ�������Դˡ���������Ҳ�������
����һ�����㷨������ѡ��0x3f3f3f3f��Ϊ�����
*/
const int N = 200003, null = 0x3f3f3f3f;

int h[N];

int find(int x)
{
	int t = (x % N + N) % N;

	while (h[t] != null && h[t] != x)//�����������ǳ�ʼ����null��Ҳ������ҪѰ�ҵ�x
	{
		t++;//������һ��λ��
		if (t == N) t = 0;//����жϵ������һ��λ�ã����ص�һ��λ�ÿ�ʼѰ��
	}

	return t;//����ǲ����򷵻��ҵ��ĵ�һ����λ�ã������Ѱ���򷵻�x���ڵ�λ��
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	memset(h, 0x3f, sizeof h);//��ʼ������ʹ������ֵ��Ϊ0x3f3f3f3f

	int n;

	cin >> n;

	while (n--)
	{
		string op;
		int x;

		cin >> op >> x;
		//����
		if (op == "I") h[find(x)] = x;
		else
		{
			//Ѱ��
			if (h[find(x)] == null) cout << "No" << endl;
			else cout << "Yes" << endl;
		}
	}

	return 0;
}