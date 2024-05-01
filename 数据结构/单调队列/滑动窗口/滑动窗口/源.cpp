#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1000010;

int n, k;
int a[N], q[N];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int hh = 0, tt = -1;//初始化hh与tt（hh为队头，tt为队尾）

	//找每个窗口的最小值
	for (int i = 0; i < n; i++)
	{
		if (hh <= tt && i - k + 1 > q[hh]) hh++;//让q中的坐标随k的移动而移动，使得q中的位置坐标始终指向k窗口中的位置坐标

		while (hh <= tt && a[q[tt]] >= a[i]) tt--;//若当前队尾坐标对应的数值大于遍历到的新数，说明此队尾坐标永远也不会用到，将队尾删除
		q[++tt] = i;//再将新数添加至队尾

		if (i >= k - 1) cout << a[q[hh]] << ' ';//若遍历次数大于窗口容量，则输出此算法结果，否则不做输出
	}
	cout << endl;

	//找每个窗口的最大值，与寻找最小值同理
	hh = 0, tt = -1;
	for (int i = 0; i < n; i++)
	{
		if (hh <= tt && i - k + 1 > q[hh]) hh++;

		while (hh <= tt && a[q[tt]] <= a[i]) tt--;
		q[++tt] = i;

		if (i >= k - 1) cout << a[q[hh]] << ' ';
	}
	cout << endl;

	return 0;
}