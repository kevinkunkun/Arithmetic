#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;//数据范围

int n;//区间个数

//区间左右端点结构体
struct Range
{
    int l, r;//左右端点
    bool operator<(const Range& w)const
    {
        return r < w.r;//定义排序方式
    }
}range[N];//区间数组

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);//输入输出优化

    cin >> n;//录入区间个数
    for (int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;//录入每个区间的左右端点

    sort(range, range + n);

    int res = 0, ed = -2e9;//定义点的个数为0
    for (int i = 0; i < n; i++)
        if (range[i].l > ed)
        {
            res++;
            ed = range[i].r;
        }

    cout << res << endl;//输出结果

    return 0;
}
