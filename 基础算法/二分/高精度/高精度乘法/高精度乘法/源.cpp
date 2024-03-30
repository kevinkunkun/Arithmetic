#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int>& A, int b)
{
	vector<int> C;

	int t = 0;
	for (int i = 0; i < A.size() || t; i++)//当A没有遍历完和t(进位)没有变成0时都不能停止，当t<10时，说明不再进位，t/10则等于0
	{
		if (i < A.size()) t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}

	while (C.size() > 1 && C.back() == 0) C.pop_back();//若b=0则会输出A个0，所以要去掉前面的0
	return C;
}

int main()
{
	string a;
	int b;

	cin >> a >> b;

	vector<int> A;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

	auto C = mul(A, b);

	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

	return 0;
}