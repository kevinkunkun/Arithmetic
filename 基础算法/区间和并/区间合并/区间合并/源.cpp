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

	int st = -2e9, ed = -2e9;//ȡ���ұ߽�ֱ�Ϊ������
	sort(segs.begin(), segs.end());
	/*
	�Ƚ��������ұ߽��С�������򡣣�C++��pair����sort����ʱ��������˵㣨��first����
	�˲������Լ򻯺������裬��ֻ��Ҫ�Ƚ������ұ߽缴��
	*/
	for (auto item : segs)
		if (ed < item.X)//���ұ߽�С��ö��������ұ߽�ʱ��˵�����������������䣬ֱ�Ӵ�������res��
		{
			if (st != -2e9) res.push_back({ st,ed });//�ж��Ƿ�Ϊ��һ��������߽磬��ֹ������Ĵ���
			st = item.X, ed = item.Y;//�������ұ߽��ֵ��������һ��ѭ��
		}
		else ed = max(ed, item.Y);//��ʱ�ұ߽����ö��������ұ߽磬˵����Ҫȡ������������ֵ���������������Ŀ��������ұ߽��С

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