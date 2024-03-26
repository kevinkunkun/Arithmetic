#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

typedef pair<int, int> PII;

vector<PII> segs;

void merge(vector<PII> &segs)
{
	vector<PII> res;

	int st = -2e9, ed = -2e9;//取左右边界分别为负无穷
	sort(segs.begin(), segs.end());
	/*
	先将所有左右边界从小到大排序。（C++中pair进行sort排序时先排序左端点（即first））
	此操作可以简化后续步骤，即只需要比较区间右边界即可
	*/
	for (auto item : segs)
		if (ed < item.X)//当右边界小于枚举区间的右边界时，说明此区间是所求区间，直接存入数组res中
		{
			if (st != -2e9) res.push_back({ st,ed });//判断是否为第一个负无穷边界，防止空区间的存入
			st = item.X, ed = item.Y;//更新左右边界的值，进行下一次循环
		}
		else ed = max(ed, item.Y);//此时右边界大于枚举区间的右边界，说明需要取两个区间的最大值（即并集）来获得目标区间的右边界大小

	if (st != -2e9) res.push_back({ st,ed });

	segs = res;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		segs.push_back({ l,r });
	}

	merge(segs);

	printf("%d", segs.size());

	return 0;
}