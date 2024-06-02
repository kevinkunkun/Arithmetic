#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;//����ͼ����ߺ��ұߣ�n1��ʾ����������n2��ʾŮ��������m��ʾ��ϵ
int h[N], e[M], ne[M], idx;//�ڽӱ�
int match[N];//Ů���������Ķ�Ӧ��ϵ�����ڶ�Ӧ��ϵ�����ܹ�ͨ��Ů��ָ���ҵ���������Ϊ�����
bool st[N];//ָ�ж�ĳ��������ѭ����Ů���Ƿ����Լ���Թ���״̬����

//�ڽӱ���뺯��
void add(int a, int b)
{
	e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

//�������㷨��ʵ�ֺ���
bool find(int x)
{
	for (int i = h[x]; i != -1; i = ne[i])//��ͷ��ʼ����������ϲ��������Ů��
	{
		int j = e[i];//ȡ�ô�Ů����λ�ñ��
		if (!st[j])//�����Ů��û����Թ�
		{
			st[j] = true;//״̬��Ϊ�����

			//�ж��Ƿ��ж�Ӧ������2�����������Ե�����2���ж����Ů����Ե�����2�Ƿ񻹴������ǵĶ���
			//����У��ͽ���ݹ�Ϊ������2(Ů�����ֶ���)���·����¶��󣬷��ش˲��Ů���Ѿ�û�����Ӧ������2��
			//��ͨ����һ�����������ж����ڲ�
			if (match[j] == 0 || find(match[j]))
			{

				//���û�ж�Ӧ������2��������������1������ƥ�䣬����Ǹ���������Ϊ���²�����Ϊ����2����Ů����2���ô�Ů��������1���
				match[j] = x;
				return true;//ƥ��ɹ�������true
			}
		}
	}

	//����ݹ鷢�������Ѿ�û�����Ƕ����ˣ�˵������ͨ�����·���������õ�Ů����ƥ��ʧ�ܣ�����false
	return false;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n1 >> n2 >> m;

	memset(h, -1, sizeof h);//��ʼ���ڽӱ�

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);//¼�����ͼ
	}

	int res = 0;
	for (int i = 1; i <= n1; i++)
	{
		memset(st, false, sizeof st);//ÿһ������ƥ��Ů��ʱ��ʹ��ͬһ��״̬���飬��ѭ��ÿһ�ζ���ʼ��Ů��״̬ΪΪƥ���
		if (find(i)) res++;//ÿ�ɹ�ƥ��һ�����������ƥ������һ
	}

	cout << res << endl;

	return 0;
}