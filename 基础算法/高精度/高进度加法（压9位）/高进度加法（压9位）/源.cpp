#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int base = 1e9;//因为压九位，所以求余与除都需要除以10的9次方

//累加函数，通过vector数组模拟加法运算
vector<int> add(vector<int>& A, vector<int>& B)
{
	if (A.size() < B.size()) return add(B, A);

	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++)
	{
		t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % base);
		t /= base;
	}

	if (t) C.push_back(t);

	return C;
}

int main()
{
	string a, b;//定义两个字符串存储两个大整数
	vector<int> A, B;//定义两个vector数组，用于存储两个大整数的每一位与运算结果

	cin >> a >> b;//录入大整数

	//将大整数1录入vector数组A中，每一次存储经历9次循环，极大的利用了int的存储范围而节省了vector数组的空间
	for (int i = a.size() - 1, s = 0, j = 0, t = 1; i >= 0; i--)
	{
		s += (a[i] - '0') * t;
		j++, t *= 10;
		if (j == 9 || i == 0)
		{
			A.push_back(s);
			s = j = 0;
			t = 1;
		}
	}

	//将大整数2录入vector数组B中，每一次存储经历9次循环，极大的利用了int的存储范围而节省了vector数组的空间
	for (int i = b.size() - 1, s = 0, j = 0, t = 1; i >= 0; i--)
	{
		s += (b[i] - '0') * t;
		j++, t *= 10;
		if (j == 9 || i == 0)
		{
			B.push_back(s);
			s = j = 0;
			t = 1;
		}
	}

	auto C = add(A, B);//通过相加函数计算出相加的结果，并通过C输出

	cout << C.back();//通过back函数访问最后一个元素，因为倒叙录入，应该倒叙输出，此方法可去掉前导零
	for (int i = C.size() - 2; i >= 0; i--) printf("%09d", C[i]);//每9位输出一位，不够的用前导零补齐（用于补充结果最后的0）
	cout << endl;

	return 0;
}