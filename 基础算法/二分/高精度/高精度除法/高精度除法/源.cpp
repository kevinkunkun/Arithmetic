#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> div(vector<int> &A, int b, int& r)
{
	r = 0;
	vector<int> C;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		r = A[i] + r * 10;
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());//由于之前的for循环倒置循环，所以让C数组中的数字排序是从高位到低位，但最终输出时也是倒置输出，所以需要将数组倒置
	while (C.size() > 1 && C.back() == 0) C.pop_back();//去掉前导0

	return C;
}

int main()
{
	string a;
	int b;
	cin >> a >> b;
	vector<int> A;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

	int r;
	auto C = div(A, b, r);
	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

	cout << endl << r << endl;

	return 0;
}