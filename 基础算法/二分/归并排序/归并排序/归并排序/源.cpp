#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1000010;

int n;
int q[N], temp[N];

void merge_sort(int q[], int l, int r)
{
	if (l >= r) return;

	int mid = l + r >> 1;
	merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r)
		if (q[i] < q[j])
			temp[k++] = q[i++];
		else
			temp[k++] = q[j++];
	while (i <= mid) temp[k++] = q[i++];
	while (j <= r) temp[k++] = q[j++];

	for (int i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &q[i]);

	merge_sort(q, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", q[i]);

	return 0;
}