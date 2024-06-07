#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;//二分图的左边和右边，n1表示男生数量，n2表示女生数量，m表示关系
int h[N], e[M], ne[M], idx;//邻接表
int match[N];//女生与男生的对应关系，存在对应关系（即能够通过女生指针找到男生）则为已配对
bool st[N];//指判断某男生当次循环中女生是否与自己配对过的状态数组

//邻接表插入函数
void add(int a, int b)
{
	e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

//匈牙利算法的实现函数
bool find(int x)
{
	for (int i = h[x]; i != -1; i = ne[i])//从头开始遍历此男生喜欢的所有女生
	{
		int j = e[i];//取得此女生的位置编号
		if (!st[j])//如果此女生没有配对过
		{
			st[j] = true;//状态置为已配对

			//判断是否有对应的男生2，如果已有配对的男生2则判断与此女生配对的男生2是否还存在心仪的对象，
			//如果有，就进入递归为此男生2(女生的现对象)重新分配新对象，返回此层后女生已经没有与对应的男生2了
			//则通过第一个条件进入判断体内部
			if (match[j] == 0 || find(match[j]))
			{

				//如果没有对应的男生2，则就让这个男生1与其相匹配，如果是更换对象则为更新操作，为男生2更新女朋友2，让此女生与男生1配对
				match[j] = x;
				return true;//匹配成功，返回true
			}
		}
	}

	//如果递归发现男生已经没有心仪对象了，说明不能通过重新分配对象来得到女生，匹配失败，返回false
	return false;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n1 >> n2 >> m;

	memset(h, -1, sizeof h);//初始化邻接表

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);//录入二分图
	}

	int res = 0;
	for (int i = 1; i <= n1; i++)
	{
		memset(st, false, sizeof st);//每一个男生匹配女生时都使用同一个状态数组，故循环每一次都初始化女生状态为为匹配过
		if (find(i)) res++;//每成功匹配一个男生，最大匹配数加一
	}

	cout << res << endl;

	return 0;
}