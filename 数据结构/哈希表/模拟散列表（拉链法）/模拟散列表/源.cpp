#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx;

//在拉练上插入x形成链表
void insert(int x)
{
	/*
	假设x为一个负数，
	若x为-10，那么正常的xmod3运算结果为：2，但在C++中，-10%3=-1
	所以为了避免负数，我们先让x对N求余，得到的结果再加上N
	得到的结果一定是一个正数，那么再modN就可以得到这个设再哈希表中的映射值
	*/
	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
}

//判断拉线上k处的链表上是否存在x
bool find(int x)
{
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i])
		if (e[i] == x)
			return true;

	return false;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	/*
	初始化h[N], 让数组值全部初始化为 - 1（代表链表的NULL）
	再通过尾插法在 - 1的下面插入新节点
	此后的每一个h[i]（i代表第i个插入的数）都会在链表的最末端（距离-1最远的地方）
	*/
	memset(h, -1, sizeof h);

	while (n--)
	{
		int x;
		string op;
		cin >> op >> x;
		if (op == "I") insert(x);
		else
		{
			if (find(x)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}

	return 0;
}