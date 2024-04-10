#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N], cnt[N];

/*
并查集算法的关键步骤（找祖宗函数）
不仅可以找祖宗，还可以实现压缩路径，减少时间复杂度
*/
int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		p[i] = i;
		cnt[i] = 1;//初始化连通块，使得每一个点对应一个连通块，其中含有一个点
	}

	while (m--)
	{
		string op;
		int a, b;

		cin >> op;
		if (op == "C")
		{
			cin >> a >> b;
			a = find(a), b = find(b);//先取出a与b的祖宗节点
			if (a != b)//若a与b的祖宗节点不同，说明不在同一数组中
			{
				p[a] = b;//将a数接在b数上
				cnt[b] += cnt[a];//并将a中存在的点加入b点的cnt数组中，实现两个连通块的联通
			}
		}
		else if (op == "Q1")
		{
			cin >> a >> b;
			if (find(a) == find(b)) cout << "Yes" << endl;//若a与b在同一连通块中输出“Yes”
			else cout << "No" << endl;//不在输出“No”
		}
		else if (op == "Q2")
		{
			cin >> a;
			cout << cnt[find(a)] << endl;//输出a节点的祖宗节点的cnt，表示这一连通块中存在的点数
		}
	}

	return 0;
}