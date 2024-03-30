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
			int mid1 = (l1 + r1) >> 1;//取中间值mid1
			if (q[mid1] >= x) r1 = mid1;//如果中间值大于等于询问值，说明我们想求得的值在中间值的左边，左移右边界
			else l1 = mid1 + 1;//反之右移左边界，记住模板令r=mid则让l=mid+1且mid不加1
		}

		if (q[l1] != x) printf("-1 -1\n");
		else
		{
			printf("%d ", l1);//先判断是否存在，若不存在输出错误返回值，存在再输出l

			int l2 = 0, r2 = n - 1;
			while (l2 < r2)
			{
				int mid2 = (l2 + r2 + 1) >> 1;//同样的，求得中间值，加一避免l=l的死循环
				if (q[mid2] <= x) l2 = mid2;//中间值所在的数组值小于询问值则说明目标值在中间值的右边，右移左边界
				else r2 = mid2 - 1;//反之左移有边界
			}

			printf("%d\n", l2);
		}
	}

	return 0;
}