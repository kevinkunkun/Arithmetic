#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int q[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &q[i]);

	while (m--)
	{
		int x;
		scanf("%d", &x);

		int l1 = 0, r1 = n - 1;
		while (l1 < r1)
		{
			int mid1 = (l1 + r1) >> 1;//ȡ�м�ֵmid1
			if (q[mid1] >= x) r1 = mid1;//����м�ֵ���ڵ���ѯ��ֵ��˵����������õ�ֵ���м�ֵ����ߣ������ұ߽�
			else l1 = mid1 + 1;//��֮������߽磬��סģ����r=mid����l=mid+1��mid����1
		}

		if (q[l1] != x) printf("-1 -1\n");
		else
		{
			printf("%d ", l1);//���ж��Ƿ���ڣ���������������󷵻�ֵ�����������l

			int l2 = 0, r2 = n - 1;
			while (l2 < r2)
			{
				int mid2 = (l2 + r2 + 1) >> 1;//ͬ���ģ�����м�ֵ����һ����l=l����ѭ��
				if (q[mid2] <= x) l2 = mid2;//�м�ֵ���ڵ�����ֵС��ѯ��ֵ��˵��Ŀ��ֵ���м�ֵ���ұߣ�������߽�
				else r2 = mid2 - 1;//��֮�����б߽�
			}

			printf("%d\n", l2);
		}
	}

	return 0;
}