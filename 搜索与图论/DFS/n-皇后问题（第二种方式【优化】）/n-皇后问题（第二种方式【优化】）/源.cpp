#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 10;

int n;
char g[N][N];
bool col[N], dg[N * 2], udg[N * 2];//�Խ���Ϊ2n-1�������Կ������Ŀռ�

void dfs(int x)
{
	if (x == n)
	{
		for (int i = 0; i < n; i++) puts(g[i]);//ʹ��puts��cout����Ч�Ҳ���д˫��ѭ��
		puts("");
		return;
	}

	for (int i = 0; i < n; i++)
		//���g[x][i]�����С��Խ��ߡ����Խ����Ͼ���Q��˵�����Ը�ֵ
		if (!col[i] && !dg[x + i] && !udg[n + i - x])
		{
			g[x][i] = 'Q';//����һ����λ�ø�ֵΪQ
			//���˵�������С��Խ��ߺͷ��Խ��߶���ֵΪtrue˵����ʹ��
			col[i] = dg[x + i] = udg[n + i - x] = true;
			dfs(x + 1);//�ݹ�ֱ����x������ȫ
			col[i] = dg[x + i] = udg[n + i - x] = false;//��ԭ
			g[x][i] = '.';//��ԭ����һ�α������ɱ�������һ�ֽ��
		}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = '.';

	dfs(0);

	return 0;
}