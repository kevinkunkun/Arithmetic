#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

/*
##结论：当P等于131或13331时，我们需要将字符串转化为数字并映射至2^64以内，这样能够最好的避免冲突##
因为unsigned long long的大小为1——2^64-1
而刚好我们的哈希表需要将数字映射至2^64内，所以直接使用unsigned long long定义数组即可
数组越界即会自动取mod，就可以省略mod的步骤
*/
typedef unsigned long long ULL;

/*
* P表示将字符变为P进制的数，因为字符一共有128个，同时也就有128个唯一的ASCII码
131为128后的第一个质数，选择此数能够最好的避免冲突，还可以选择13331作为P
*/
const int N = 100010, P = 131;

int n, m;
char str[N];
ULL h[N], p[N];

int get(int l, int r)
{
	/*
	请先阅读第54—57行注释
	假如：计算h[DEF]
	h[DEF]=h[ABCDEF]-h[ABC]
	举例：
	h[ABC]='A'*P^2+'B'*P^1+'C'*P^0;
	h[ABCDEF]='A'*P^5+'B'*P^4+'C'*P^3+'D'*P^2+'E'*P^1+'F'*P^0
	由此可见：此时h[ABCDEF]中的ABC与h[ABC]中的ABC权重不一致，无法直接相减
	解决方案：我们只需要将h[ABC]乘以一个数使得其位权等于h[ABCDEF]中ABC的位权即可相减
	观察可知，这个数就是P的某次方，刚好我们存了每一个位置的位权在p数组中
	我们将l-1位置乘以其与r位置相差的位权即为r位置的位权即 r-(l-1)
	*/
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	cin >> str + 1;//让str数组从第一个数开始装填，方便后续哈希表的装填

	p[0] = 1;//第一个数从1开始，从0开始会发生冲突
	for (int i = 1; i <= n; i++)
	{
		/*
		这里我们每进一位都将原来的位置乘以P来扩大了每个位置的位权，
		同时加上str[i]来让其对应相应字母的哈希值
		（位权即为每一位置上的位置权重，如二进制中10，1就是1*2^1,0就是0*2^0）
		p数组也随着h数组中数字的权重变化相同变化权重，记录每一个对应位置的权重
		*/
		h[i] = h[i - 1] * P + str[i];
		p[i] = p[i - 1] * P;
	}

	while (m--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (get(l1, r1) == get(l2, r2)) cout << "Yes"<<endl;
		else cout << "No" << endl;
	}

	return 0;
}