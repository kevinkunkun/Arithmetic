#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> &A, vector<int> &B)//�Ƚ�A��B�Ĵ�С�ĺ��������A���򷵻�true����֮����fasle
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
		C.push_back((t + 10) % 10);//���������Ĳ�С��0�������10�����C�У�������0��ֱ�ӱ����C��
		if (t >= 0) t = 0;
		else t = 1;//�ж���λ���Ĳ��Ƿ����0����С��0������t=1����һ�ν��и���λ�ļ���ʱ���һ�����λ
	}

	while (C.size() > 1 && C.back() == 0) C.pop_back();//���𰸵ĸ�λ�ϴ��ڵ�0ȥ��
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
	else C=sub(B, A), cout << '-';//�ж�A��B�Ĵ�С�����A������Ϊ����ֱ��ʹ��sub���������B������Ϊ���������ʱ��Ҫ���ϡ�-����

	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
	cout << endl;

	return 0;
}