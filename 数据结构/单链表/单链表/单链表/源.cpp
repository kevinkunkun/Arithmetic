#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

/*
head表示单链表的头节点得下标，是第一个指针
e[N]表示一个值，具体为指针指向的节点的值
ne[N]表示一个指针，具体表示为此节点指向的下一个节点的指针
idx表示一个指针，主要用于创建新节点，并表示当前使用的点的下标
*/
int head,e[N], ne[N], idx;

/*
作用：初始化链表
赋值head=-1，即让head在数组中指向空
idx初始化为0，即从数组第一个数开始遍历，不浪费数组资源
*/
void init()
{
	head = -1;
	idx = 0;
}

/*
作用：在头节点head与第一个点之间插入一个新的点，并将其值赋值为x.
主要过程分为3步：
1.为先将x的值存入e[idx]中.
2.创建一个新指针ne[x]并将ne[idx]初始化为指向head所指向的节点.
3.将head的值更改为idx，使得head所指向的值为当初idx所指向的值，即x.
再将idx的值自增，让idx指向数组中下一个未使用空间
*/
void add_to_head(int x)
{
	e[idx] = x;
	ne[idx] = head;
	head = idx++;
}

/*
作用：在插入的第k个节点后再插入一个新的节点，值为x.
与在头节点插入新节点类似，也分为三步：
1.为先将x的值存入e[idx]中（idx可以是任何值，知识代表一个新指针，指向数组中的一个新节点）.
2.创建一个新指针ne[x]并将ne[idx]初始化为指向第k个节点所指向的节点.
3.将指向第k个节点的指针的值更改为idx的值，使得第k个节点所指向的值为当初idx所指向的值，即x.
再将idx的值自增，让idx指向数组中下一个未使用空间
*/
void add(int k, int x)
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx++;
}

/*
作用：去掉k所指向的节点（使得第k个插入链表的节点指向其所指向的节点所指向的节点）
步骤分为2步：
1.先初始化ne[k]指针表示k指向节点
2.在初始化ne[ne[k]]指针表示k指向的数所指向的节点，并将此指针ne[ne[k]]赋给ne[k]，
代表k现在指向之前kk指向的数所指向的节点，这样便实现了去掉了k所指向的节点
*/
void remove(int k)
{
	ne[k] = ne[ne[k]];
}

/*
本算法使用数组模拟链表，
因为在C++中new（）动态分配一块节点是非常慢的，在算法比赛中容易超时
使用数组模拟则更简便，所以在本算法中，能够放入[]中的值皆为指针
*/
int main()
{
	int m;

	cin >> m;

	init();

	while (m--)
	{
		int x, k;
		char op;

		cin >> op;

		if (op == 'H')
		{
			cin >> x;
			add_to_head(x);
		}
		else if (op == 'D')
		{
			cin >> k;
			if (!k) head = ne[head];
			remove(k-1);
		}
		else
		{
			cin >> k >> x;
			add(k - 1, x);
		}
	}

	for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
	cout << endl;

	return 0;
}