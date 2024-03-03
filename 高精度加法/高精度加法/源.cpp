#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>//使用动态数组vector存储

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)//vector中的参数取地址，记得加&
{
	if (A.size() < B.size()) return add(B, A);//默认A比B长，若B更长则改变A与B的位置

	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++)
	{
		t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);//将得到的和mod10后存入C的末尾
		t /= 10;
	}

	if (t) C.push_back(t);
	return C;
}

int main()
{
	string a, b;
	cin >> a >> b;
	vector<int> A, B;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');//从最后一位开始存入数组，让数组的末尾为数字的首位，方便进位
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

	auto C = add(A, B);
	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

	return 0;
}