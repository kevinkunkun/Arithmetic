#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N], s[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);

	int res = 0;
	for (int i = 0,j=0; i < n; i++)
	{
		s[q[i]]++;//���ƹ�ϣ��������iʱq�е�����s�м�һ
		while (j < n && s[q[i]]>1) s[q[j++]]--;
		/*
		���s[q[i]]����1˵�������ֱ����˲�ֹһ�Σ�������s�����j��ʼ��һ��
		ֱ���ô����ֵĴ�������1��
		��ʱjָ��ָ������ֵ�i֮�����һ��ʱ���ظ���
		*/
		res = max(res, i - j + 1);//ֻ��Ҫ�����еĽ����ȡ�����ֵ���������
	}

	printf("%d", res);

	return 0;
}