#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

//����ߵ����ݷ�ΧΪ100000����Ϊ������ͼ�����Աߵķ�Χ����ֵ����
const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;//�ڽӱ�����
int color[N];//Ⱦɫ����

//�ڽӱ�Ĳ��뺯��
void add(int a, int b)
{
	e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

//������ޱ�������
bool dfs(int u, int c)
{
	color[u] = c;//��color������uλ��Ⱦ��c(Ҳ����1����ʾ��ɫ)

	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];//ȡ���ڽӱ���������Ӧ�Ĳ���˳��
		if (!color[j])//���û�б�Ⱦɫ
		{
			//�ݹ����������������������ڵ���һ�������ݹ����ȾɫΪ��ɫ���ɫ����Ⱦɫ��ֱ�����������ڽӱ�
			//�ݹ�����е�������ֹ�����
			//���һ�������û��Ⱦ��ɫ��Ҳû�з���ֵ���������Ⱦ��3-c(Ҳ����2����ʾ��ɫ),�����������һ���㣬ֱ�����һ���㣬���뱾��Ⱦɫ��ֵ��ͬ������true����ͼΪ����ͼ
			//������������Ⱦ��ɫ������Ⱦɫֵ�뱾��Ⱦɫ��ֵ��ͬ��˵�������ͼ�ı�����ì�ܣ�����false
			if (!dfs(j, 3 - c)) return false;
		}
		else if (color[j] == c) return false;
	}

	return true;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);//��������Ż�

	cin >> n >> m;

	memset(h, -1, sizeof h);//��ʼ���ڽӱ�ͷ

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);//¼������ͼ
	}

	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		if (!color[i])//���û��Ⱦ��ɫ
		{
			if (!dfs(i, 1))//����dfsȾɫ���ж��Ƿ��������ͼ������
			{
				flag = false;//��¼dfs�Ľ�����߼�ֵ��dfs����ͬ
				break;//����ѭ������Ϊ�Ѿ������϶���ͼ�������ˣ��������ѭ��
			}
		}
	}

	if (flag) puts("Yes");
	else puts("No");

	return 0;
}