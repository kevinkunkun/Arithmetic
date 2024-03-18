#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second
using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

int find(int x)
{
	int l = 0, r = alls.size() - 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}//整数二分算法，r=mid所以l+r不需要+1

	return r + 1;//因为要使用到一维前缀和的算法，由于a数组从0开始，而前置缀和算法要求从1开始避免考虑边界问题
}

vector<int>::iterator unique(vector<int> &a)
{
	int j=0;
	for (int i = 0; i < a.size(); i++)
	{
		if (!i || a[i] != a[i - 1])//如果此数是第一个或者与前一个数不相等则存入a数组中，实现去重
			a[j++] = a[i];
	}

	return a.begin() + j;
}//补充unique函数算法，C++中含有此函数，此处解释其具体实现过程

int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int x, c;
		scanf("%d%d", &x, &c);
		add.push_back({ x,c });//将位置与加数存入add数组中
		alls.push_back(x);//将做加法的位置存入alls数组中
	}

	for (int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		query.push_back({ l,r });//将左右位置存入query数组中
		alls.push_back(l);//将左边界位置存入alls数组中
		alls.push_back(r);//将右边界位置存入alls数组中
	}

	sort(alls.begin(), alls.end());//将alls数组中的位置进行排序
	alls.erase(unique(alls), alls.end());
	/*
	将排序后的alls数组去重，先将重复元素交换至数组最后，再将数组后面的元素删除，
	若此处使用C++的函数unique则需要写成：alls.erase(unique(alls.begin(), alls.end()), alls.end());
	*/

	for (auto item:add)
	{
		int x = find(item.X);
		a[x] += item.Y;//使用add数组中的位置与加数，将其位置对应的a数组中位置加上加数
	}

	for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];//将a数组进行一维前缀和算法

	for (auto item : query)
	{
		int l = find(item.X), r = find(item.Y);
		/*
		使用query数组中的位置对应alls中的位置，再对应输出区间中的前缀和得到区间和
		*/
		printf("%d\n", s[r] - s[l - 1]);
	}

	return 0;
}