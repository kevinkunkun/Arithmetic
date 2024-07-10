#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int base = 1e9;//��Ϊѹ��λ�����������������Ҫ����10��9�η�

//�ۼӺ�����ͨ��vector����ģ��ӷ�����
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
	string a, b;//���������ַ����洢����������
	vector<int> A, B;//��������vector���飬���ڴ洢������������ÿһλ��������

	cin >> a >> b;//¼�������

	//��������1¼��vector����A�У�ÿһ�δ洢����9��ѭ���������������int�Ĵ洢��Χ����ʡ��vector����Ŀռ�
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

	//��������2¼��vector����B�У�ÿһ�δ洢����9��ѭ���������������int�Ĵ洢��Χ����ʡ��vector����Ŀռ�
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

	auto C = add(A, B);//ͨ����Ӻ����������ӵĽ������ͨ��C���

	cout << C.back();//ͨ��back�����������һ��Ԫ�أ���Ϊ����¼�룬Ӧ�õ���������˷�����ȥ��ǰ����
	for (int i = C.size() - 2; i >= 0; i--) printf("%09d", C[i]);//ÿ9λ���һλ����������ǰ���㲹�루���ڲ���������0��
	cout << endl;

	return 0;
}