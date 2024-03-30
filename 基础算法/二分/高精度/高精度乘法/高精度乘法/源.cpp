#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int>& A, int b)
{
	vector<int> C;

	int t = 0;
	for (int i = 0; i < A.size() || t; i++)//��Aû�б������t(��λ)û�б��0ʱ������ֹͣ����t<10ʱ��˵�����ٽ�λ��t/10�����0
	{
		if (i < A.size()) t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}

	while (C.size() > 1 && C.back() == 0) C.pop_back();//��b=0������A��0������Ҫȥ��ǰ���0
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