#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

typedef long long LL;
const int N = 100010;

int n;
int q[N], temp[N];

LL merge_sort(int q[], int l, int r)
{
	if (l >= r) return 0;

	int mid = l + r >> 1;
	int i = l, j = mid + 1, k = 0;
	LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

	//�鲢����
	while (i <= mid && j <= r)
	{
		if (q[i] <= q[j]) temp[k++] = q[i++];
		else
		{
			temp[k++] = q[j++];
			res += mid - i + 1;
		}
	}

	//ɨβ
	while (i <= mid) temp[k++] = q[i++];
	while (j <= r) temp[k++] = q[j++];

	//���ԭ��
	for (int i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];

	return res;
}
int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d", &q[i]);

	cout << merge_sort(q, 0, n - 1) << endl;

	return 0;
}