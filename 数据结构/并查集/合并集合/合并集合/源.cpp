#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N];

int find(int x)
{
	/*
	若x的父节点不是x，则递归find（一直向上遍历）
	此操作不仅能够找到x的祖宗节点，还能够优化查找算法的时间复杂度，实现路径压缩
	每一个节点只有第一遍需要遍历所有节点到父节点，之后的每一次都只需要一遍即可
	所以并查集算法的时间复杂度接近于O(1)
	*/
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) p[i] = i;

	while (m--)
	{
		char op;
		int a, b;

		cin >> op >> a >> b;

		//让b的祖宗节点等于a节点的祖宗节点的父节点即实现了两个集合的合并
		if (op == 'M') p[find(a)] = find(b);
		//若两个节点的父节点相同，说明两个节点在同一集合中，则输出"Yes",否则输出"No"
		else if (find(a) == find(b)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}