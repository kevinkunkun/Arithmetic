#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 1010;

int n;
int C[N][N];

int main()
{
	cout << "������������ǵ�����" << endl;
	cin >> n;
	system("cls");
	cout << "����Ϊ"<<n<<"�е��������" << endl;

	for (int i = 0; i <= n; i++)
	{
		for (int k = 0; k < n - i; k++)
			cout << ' ';
		for (int j = 0; j <= i; j++)
		{
			if (!j)
				C[i][j] = 1;
			else
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			cout << C[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
