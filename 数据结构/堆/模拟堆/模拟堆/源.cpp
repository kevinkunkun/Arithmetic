#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

/*
h[N]数组就是堆，其中存放的就是按顺序排放的堆
hp[N]数组代表由堆指向指针，其中存放的是第i个存放到堆中的数中的i
ph[N]数组代表由指针指向堆，其中存放的是第i个存放到堆中在堆中的序号k
（通过k我们可以找到这个数在堆中的具体位置）
cnt代表目前堆所使用到的大小
*/
int h[N], hp[N], ph[N], cnt;

void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);//三个操作可以调换顺序，操作的目的是便于维护堆
}

//下降操作假设h[x]是一个特别大的数，需要向下降
void down(int x)
{
	int t = x;
	if (x * 2 <= cnt && h[x * 2] < h[t]) t = x * 2;
	if (x * 2 + 1 <= cnt && h[x * 2 + 1] < h[t]) t = x * 2 + 1;
	if (x != t)
	{
		heap_swap(x, t);
		down(t);
	}
}

//上身操作假设h[x]是一个特别小的数，需要向上升
void up(int x)
{
	while (x / 2 && h[x] < h[x / 2])//如果x存在父亲，且h[x]比他的父亲更小
	{
		heap_swap(x, x / 2);//交换两个数的位置
		x /= 2;//让x变为其父亲，继续循环直到其祖宗节点
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m = 0;
	cin >> n;

	while (n--)
	{
		string op;
		int k, x;

		cin >> op;
		//插入新元素x
		if (op == "I")
		{
			cin >> x;
			cnt++;//扩充堆的容量
			m++;
			/*
			每插入一个数，都要进行记录：
			ph[]：在堆中的序号（在顺序排序的堆中的序号）
			hp[]：其插入时的序号（第几个插入）
			*/
			ph[m] = cnt, hp[cnt] = m;
			h[cnt] = x;
			up(cnt);
		}
		//输出头节点，即最小值
		else if (op == "PM") cout << h[1] << endl;
		//去除头节点，即最小值
		else if (op == "DM")
		{
			heap_swap(1, cnt);
			cnt--;
			down(1);
		}
		//删除第k个插入的数
		else if (op == "D")
		{
			cin >> k;
			k = ph[k];//去ph[]数组中寻找第k个插入的数在堆中现在的排序序号
			heap_swap(k, cnt);//将这个序号与最后一个数交换
			cnt--;//去掉最后一个数，最后一个属即为交换前的第k个插入的数
			up(k);
			down(k);//交换操作肯定会带来顺序的变化，up或down一遍就行
		}
		else
		{
			cin >> k >> x;
			k = ph[k];//去ph[]数组中寻找第k个插入的数在堆中的序号
			h[k] = x;//将堆中此序号对应的值改为x
			/*
			修改操作可能会带来大小顺序的变化，因此需要对堆进行重新排序
			因为不知道此数在堆中具体应该向上升还是向下降，
			所以up和down都执行一次即可实现所有情况的排序。
			虽然每一次都会会执行两个函数，但对堆顺序产生变化的只有其中一个函数
			*/
			up(k);
			down(k);
		}
	}

	return 0;
}