#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m, x;
int a[N], b[N];

int main()
{
	//��������ٶ��Ż�
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> x;

	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < m; i++) cin >> b[i];
	//˫ָ���Ż���ʱ�临�Ӷ���O��n*m����ΪO(n+m)��ֻ�ʺ�����Ψһ�������
	for (int i = 0, j = m - 1; i < n; i++)
	{
		while (j >= 0 && a[i] + b[j] > x) j--;
		if (j >= 0 && a[i] + b[j] == x) cout << i << ' ' << j << endl;
	}

	return 0;
}
