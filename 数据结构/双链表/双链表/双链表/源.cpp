#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int e[N], l[N], r[N], idx;

void init()
{
	r[0] = 1, l[1] = 0;//初始化两个节点，作为永不会消失的两个左右节点
	idx = 2;
}

void insert(int k, int x)
{
	e[idx] = x;//先将x的值存入idx指针指向的数组空间中
	r[idx] = r[k];//将k节点指向右侧的值赋给idx指向右侧的指针，实现复制指针
	l[idx] = k;//将idx的左指针指向k
	l[r[k]] = idx;//断掉k节点指向的右节点的左指针，并让idx指向的节点指向k节点
	r[k] = idx++;//断掉k节点的右指针，并让其指向idx指向的节点，并让idx自增开辟出新的空间方便下一次插入操作
}

void remove(int k)
{
	l[r[k]] = l[k];//把k节点指向的左边节点的值赋给k节点指向的右边节点的左指向
	r[l[k]] = r[k];//把k节点指向的右边节点的值赋给k节点指向的左边节点的右指向
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	init();

	while (n--)
	{
		string op;
		int x, k;

		cin >> op;
		if (op == "L")
		{
			cin >> x;
			insert(0, x);
		}
		else if (op == "R")
		{
			cin >> x;
			insert(l[1], x);
		}
		else if (op == "D")
		{
			cin >> k;
			remove(k + 1);
			/*
			k + 1原理类似单链表的k - 1。因为双链表始终存在一头一尾两个点
			所以双链表数组中始终需要两个空间来存储左右指针的初始位置，
			由于数组空间的占用，且指针无法重复利用以被占用的位置的空间，
			则令数组全体向后移动两位，使得k-1变为k-1+2=k+1.
			*/
		}
			
		else if (op == "IL")
		{
			cin >> k >> x;
			insert(l[k + 1], x);
		}
		else
		{
			cin >> k >> x;
			insert(k + 1, x);
		}
	}

	for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
	cout << endl;

	return 0;
}