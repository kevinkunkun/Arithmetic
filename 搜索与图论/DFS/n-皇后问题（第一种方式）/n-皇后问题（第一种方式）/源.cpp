#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 10;

int n;
char g[N][N];
bool row[N], col[N], dg[N * 2], udg[N * 2];

void dfs(int x, int y, int s)//x��ʾ�����꣬y��ʾ�����꣬s��ʾ�ʺ����
{
	if (s > n) return;//���ʺ���������ܸ�����ֱ�ӷ���

	if (y == n) y = 0, x++;//����y����ÿһ�е����һ��������y����0��x++������һ��

	if (x == n)//�����������֮���һ��
	{
		if (s == n)//��ÿһ���ʺ�������
		{
			for (int i = 0; i < n; i++) puts(g[i]);//������
			puts("");
		}
		return;
	}

	g[x][y] = '.';//ÿ�ݹ�һλ�þ͸��丳ֵΪ'.'
	dfs(x, y + 1, s);//���һ�в��ӻʺ�ֱ��������һ��

	if (!row[x] && !col[y] && !dg[x + y] && !udg[y - x + n])//���һ��λ���ϵ������С��С��Խ��ߡ����Խ����϶�û�лʺ�
	{
		g[x][y] = 'Q';//���Ը�ֵΪQ
		row[x] = col[y] = dg[x + y] = udg[y - x + n] = true;//����״̬Ϊ��ʹ��
		dfs(x, y + 1, s + 1);//�ݹ����ֱ�����һ��
		row[x] = col[y] = dg[x + y] = udg[y - x + n] = false;//��ԭ
		g[x][y] = '.';//��ԭ
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	dfs(0, 0, 0);

	return 0;
}