#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>//ʹ�ö�̬����vector�洢

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)//vector�еĲ���ȡ��ַ���ǵü�&
{
	if (A.size() < B.size()) return add(B, A);//Ĭ��A��B������B������ı�A��B��λ��

	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++)
	{
		t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);//���õ��ĺ�mod10�����C��ĩβ
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
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');//�����һλ��ʼ�������飬�������ĩβΪ���ֵ���λ�������λ
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

	auto C = add(A, B);
	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

	return 0;
}