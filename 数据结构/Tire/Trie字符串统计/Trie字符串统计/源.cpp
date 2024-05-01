#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

/*
son��ά�����У�
N��Ԫ�ص�ά�ȴ����Tire���ĵ�������26��Ԫ�ص�ά�ȴ�������е���һ��Ӣ����ĸ
cnt[N]�����д洢ͬһ�ַ������ֵĴ�������û��������ַ�����Ϊ0��
idx��ʾ��ǰ��ʹ�ù��Ľڵ���
*/
int son[N][26], cnt[N], idx;
char str[N];

void insert(char* str)
{
	int p = 0;
	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';//��a-zӳ�䵽0-25
		/*
		�������ڴ˽ڵ㣬�򴴽�һ���½ڵ㣬
		�����ڵ���idx��ֵ�����󸳸�son[p][u]��ʾ��Tire���д˽ڵ������
		*/
		if (!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++;//�����ַ��������һ�м�һ����ǣ�����ʾ��ǰ���������ֹ�һ�Σ����ƹ�ϣ��
}

int query(char* str)
{
	int p = 0;
	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if (!son[p][u]) return 0;//�������ڴ˽ڵ㣬�򷵻�0
		p = son[p][u];//son[p][u]�е�ֵ����ǰ�ڵ���ָ�����һ���������������丳��p������һ�εĲ���
	}
	return cnt[p];//�����ڴ��ַ������򷵻��ַ������ֵĴ���
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	while (n--)
	{
		char op[2];
		cin >> op >> str;
		if (*op == 'I') insert(str);
		else cout << query(str) << endl;
	}

	return 0;
}
