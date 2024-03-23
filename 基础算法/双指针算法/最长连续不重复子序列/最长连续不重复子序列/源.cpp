#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N], s[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);

	int res = 0;
	for (int i = 0,j=0; i < n; i++)
	{
		s[q[i]]++;//类似哈希表，将遍历i时q中的数在s中加一
		while (j < n && s[q[i]]>1) s[q[j++]]--;
		/*
		如果s[q[i]]大于1说明此数字被加了不止一次，所以让s数组从j开始减一，
		直到让此数字的次数减至1，
		此时j指针指向的数字到i之间的数一定时不重复的
		*/
		res = max(res, i - j + 1);//只需要在所有的结果中取得最大值即可求出答案
	}

	printf("%d", res);

	return 0;
}