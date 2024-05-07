#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b; ne[idx] = h[a]; w[idx] = c; h[a] = idx++;
}

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	dist[1] = 0;
	heap.emplace(0, 1);

	while (heap.size())
	{
		auto t = heap.top();
		heap.pop();

		int ver = t.second;
		if (st[ver]) continue;
		st[ver] = true;

		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[ver] + w[i])
				dist[j] = dist[ver] + w[i];
			heap.emplace(dist[j], j);
		}
	}

	if (dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	memset(h, -1, sizeof h);

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}

	cout << dijkstra() << endl;

	return 0;
}