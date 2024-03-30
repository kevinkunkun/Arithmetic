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
	}

	return r + 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int x, c;
		scanf("%d%d", &x, &c);
		add.push_back({ x,c });
		alls.push_back(x);
	}

	for (int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		query.push_back({ l,r });
		alls.push_back(l);
		alls.push_back(r);
	}

	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());

	for (auto item : add)
	{
		int x = find(item.X);
		a[x] += item.Y;
	}

	for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

	for (auto item : query)
	{
		int l = find(item.X), r = find(item.Y);
		printf("%d\n", s[r] - s[l - 1]);
	}

	return 0;
}