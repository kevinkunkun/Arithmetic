#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(string state)
{
	unordered_map<string,int> d;//创建哈希表d
	queue<string> q;//创建队列q

	string end = "12345678x";//定义最终效果

	q.push(state);//将初态加入队列
	d[state] = 0;//将初态与出台之间的变化步骤次数定义为0

	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };//初始化上下左右的遍历方向
	while (q.size())
	{
		auto t = q.front();//取q队列的首元素为t
		q.pop();//弹出首元素

		if (t == end) return d[t];//如果达到了最终效果，直接返回此时的变换次数

		int distance = d[t];//将的t对应哈希表中的值取出并赋值给distance
		int k = t.find('x');//在字符串中找的x的对应下标
		int x = k / 3, y = k % 3;//x，y分别表示'x'在3*3矩阵中的横坐标与纵坐标

		for (int i = 0; i < 4; i++)//遍历四个方向
		{
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && a < 3 && b >= 0 && b < 3)
			{
				swap(t[a * 3 + b], t[k]);//符合条件即交换两个数在字符串中的对应位置
				if (!d.count(t))
				{
					d[t] = distance + 1;//若此时的t未在哈希表中存在过，使其对应的变化值加一
					q.push(t);//并将其放入队列进行下一次的遍历
				}
				swap(t[a * 3 + b], t[k]);//还原两数的位置，方便剩余三组的遍历
			}
		}
	}

	return -1;//若队列循环完全但未达到最终效果说明不能变化成最终效果，返回-1
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	char s[2];//方便读入空格

	string state;

	//读入字符串
	for (int i = 0; i < 9; i++)
	{
		cin >> s;
		state += *s;
	}

	cout << bfs(state) << endl;

	return 0;
}