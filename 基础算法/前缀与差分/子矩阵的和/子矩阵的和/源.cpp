#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1010;

int n, m, q;
int s[N][N];

int main()
{
	scanf("%d%d%d", &n, &m, &q);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &s[i][j]);//���������ݣ�����������

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];//�����е�Ԫ��ǰ׺��ͨ������ԭ���������Ϊs[i][j]ԭ�������Ŀ��ֵ�����Ե���Ҫʹ�ô˵�Ԫ�е���ʱֱ�����ü���

	while (q--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);//ͨ������ԭ���֮ǰ��������е�Ԫ��ǰ׺���������������Ԫ֮�����ĺ�
	}

	return 0;
}