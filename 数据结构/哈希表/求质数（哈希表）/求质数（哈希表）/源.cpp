#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

/*
�˺������ڹ�ϣ���������100000����С���������Ϊ100003��
�����ݷ�Χ�����仯ʱ����ʹ�ô˺���������ݷ�Χ��Ϊ���㡣
ע�����ڹ�ϣ�д��ڳ�ͻ���������ʹ�õ�modNһ��Ҫ��ѧ�Ͻ���
������ѧ֤����N��ֵΪ�������ݷ�Χ����С��������������������2��n�η���ֵ��Զ��ʱ��������ͻ�ĸ�����С
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
            cout << i << endl;//������Ϊ100003
            break;
        }
    }

    return 0;
}