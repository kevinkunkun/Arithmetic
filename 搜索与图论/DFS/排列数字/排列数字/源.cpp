#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N];

void dfs(int u, int state)
{
	if (u == n)//����Ѿ�������λ�õ���n���������ǰ�Ѿ���������path����
	{
		for (int i = 0; i < n; i++) cout << path[i] << ' ';
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++)//����Ѿ�������λ�û�û�е�n
	{
		if (!(state >> i & 1))//�ж�state�������еĵ�iλ�Ƿ�Ϊ0
		{
			/*
			���Ϊ0������path����ĵ�uλ����i+1��
			��Ϊ����ʽ�����Ǵ�1��n���б������������ǵ�i�Ǵ�0��ʼ�ģ�����Ҫ��i+1
			*/
			path[u] = i + 1;
			/*
			�ݹ������ÿһ�δ���u+1��ʹ��u��0��һ������nֱ�����������һ��Ԫ�أ�
			���Ѳ�����==nʱֹͣ������state�ĵ�iΪ��Ϊ1����ʾ��ǰλ���ѱ�ʹ��
			��Ϊÿ���һ�ν����dfs�е�state�������¶��壬
			���Կ��Ժܷ����ͨ��������λ���㱣��ÿһ�β�����ÿһ�εݹ��״̬
			*/
			dfs(u + 1, state + (1 << i));
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	dfs(0,0);//��0��ʼ������ֱ����n-1����������n����ʱ�������ʼ״̬Ϊ0

	return 0;
}