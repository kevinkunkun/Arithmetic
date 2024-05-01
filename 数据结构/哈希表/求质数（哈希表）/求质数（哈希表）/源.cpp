#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

/*
此函数用于哈希表中求大于100000的最小质数，结果为100003，
在数据范围发生变化时，则使用此函数求的数据范围较为方便。
注：由于哈希中存在冲突情况，所以使用的modN一定要科学严谨，
经过数学证明，N的值为大于数据范围的最小质数（备用条件：距离2的n次方数值最远）时，产生冲突的概率最小
*/
int main()
{

    for (int i = 100000;; i++)
    {
        bool flag = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << i << endl;//输出结果为100003
            break;
        }
    }

    return 0;
}