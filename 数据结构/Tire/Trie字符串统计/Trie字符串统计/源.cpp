#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

/*
son二维数组中，
N个元素的维度代表此Tire树的的行数，26个元素的维度代表此行中的哪一个英文字母
cnt[N]数组中存储同一字符串出现的次数，若没有输入此字符串则为0次
idx表示当前已使用过的节点数
*/
int son[N][26], cnt[N], idx;
char str[N];

void insert(char* str)
{
	int p = 0;
	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';//将a-z映射到0-25
		/*
		若不存在此节点，则创建一个新节点，
		并将节点数idx的值自增后赋给son[p][u]表示在Tire数中此节点的行数
		*/
		if (!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++;//将此字符串的最后一行加一（标记），表示当前遍历完后出现过一次（类似哈希表）
}

int query(char* str)
{
	int p = 0;
	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if (!son[p][u]) return 0;//若不存在此节点，则返回0
		p = son[p][u];//son[p][u]中的值代表当前节点所指向的下一个结点的行数，将其赋给p便于下一次的查找
	}
	return cnt[p];//若存在此字符串，则返回字符串出现的次数
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	while (n--)
	{
		char op[2];
		cin >> op >> str;
		if (*op == 'I') insert(str);
		else cout << query(str) << endl;
	}

	return 0;
}
