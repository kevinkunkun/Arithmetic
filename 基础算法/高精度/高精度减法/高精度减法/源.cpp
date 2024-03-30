#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> &A, vector<int> &B)//比较A与B的大小的函数，如果A大则返回true，反之返回fasle
{
	if (A.size() != B.size()) return A.size() > B.size();
	for (int i = A.size() - 1; i >= 0; i--)
		if (A[i] != B[i])
			return A[i] > B[i];
	return true;
}

vector<int> sub(vector<int>& A, vector<int>& B)
{
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++)
	{
		t = A[i] - t;
		if (i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);//若两个数的差小于0，则加上10保存进C中，若大于0则直接保存进C中
		if (t >= 0) t = 0;
		else t = 1;//判断两位数的差是否大于0，若小于0，则令t=1，下一次进行更高位的减法时多减一完成退位
	}

	while (C.size() > 1 && C.back() == 0) C.pop_back();//将答案的高位上存在的0去掉
	return C;
}

int main()
{
	string a, b;
	vector<int> A, B;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

	vector<int> C;

	if (cmp(A, B)) C=sub(A, B);
	else C=sub(B, A), cout << '-';//判断A与B的大小，如果A大则结果为正，直接使用sub函数；如果B大则结果为负，在输出时需要加上‘-’；

	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
	cout << endl;

	return 0;
}