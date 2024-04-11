#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N], d[N];//定义p[N]为x指向其父节点的指针数组，的d[N]为x节点到其祖宗节点的路径长度

//并查集的找祖宗函数
int find(int x)
{
	if (p[x] != x)
	{
		int t = find(p[x]);//先递归，将x的祖宗节点存到t中
		/*
		经过递归，路径已被压缩，此时p[x]指向父节点就是祖宗节点，且路径长已经递归求出，
		累加即可求出x节点到祖宗节点的路径长度
		*/
		d[x] += d[p[x]];
		p[x] = t;//将x指向其祖宗节点，实现路径压缩
	}
	return p[x];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) p[i] = i;//初始化p[N]数组，使得每一个节点都指向其唯一的一个父节点

	int res = 0;
	while (m--)
	{
		int t, x, y;
		cin >> t >> x >> y;
		if (x > n || y > n) res++;//如果此说法的物种数大于物种的总类别数，说明其肯定是假话
		else
		{
			int px = find(x), py = find(y);//让px、py分别等于x、y的祖宗节点

			/*
			首先，如果x与y在同一集合中时，经过数学分析发现：
			一个节点与祖宗节点之间的距离与其与祖宗节点之间的关系满足以下三条：
			①：若距离mod3余数等于0，说明其与其祖宗节点是同类
			②：若距离mod3余数等于1，说明其与其祖宗节点是其能吃其祖宗节点
			③：若距离mod3余数等于2，说明其与其祖宗节点是其能被其祖宗节点吃
			*/
			if (t == 1)//判断以一种情况（x与y是否是同类？）
			{
				/*
				此处判断x与y是否是同类，
				所以除了x与y的距离差在mod3的情况下余数为0的情况，其他全为假话，res++
				*/
				if (px == py && (d[x] - d[y]) % 3) res++;
				else if(px!=py)//如果x与y不在同一集合，那就让x与y所在两个集合合并
				{
					p[px] = py;//让y成为x的父节点

					/*
					x到y的距离(d[px])满足以下数学关系：
					(d[x]+d[px]-d[y])%3=0
					化简得：d[px]=d[y]-d[x]
					*/
					d[px] = d[y] - d[x];
				}
			}
			else
			{

				/*
				此处判断x是否能吃y，
				所以除了x与y的距离差在mod3的情况下余数为1的情况，其他全为假话，res++
				*/
				if (px == py && (d[x] - d[y] - 1) % 3) res++;
				else if(px!=py)//如果x与y不在同一集合，那就让x与y所在两个集合合并
				{
					p[px] = py;//让y成为x的父节点

					/*
					x到y的距离(d[px])满足以下数学关系：
					(d[x]-1+d[px]-d[y])%3=0
					化简得：d[px]=d[y]-d[x]+1
					*/
					d[px] = d[y] - d[x] + 1;
				}
			}
		}
	}

	cout << res << endl;

	return 0;
}