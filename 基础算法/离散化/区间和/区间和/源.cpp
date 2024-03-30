#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second
using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

int find(int x)
{
	int l = 0, r = alls.size() - 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}//���������㷨��r=mid����l+r����Ҫ+1

	return r + 1;//��ΪҪʹ�õ�һάǰ׺�͵��㷨������a�����0��ʼ����ǰ��׺���㷨Ҫ���1��ʼ���⿼�Ǳ߽�����
}

vector<int>::iterator unique(vector<int> &a)
{
	int j=0;
	for (int i = 0; i < a.size(); i++)
	{
		if (!i || a[i] != a[i - 1])//��������ǵ�һ��������ǰһ��������������a�����У�ʵ��ȥ��
			a[j++] = a[i];
	}

	return a.begin() + j;
}//����unique�����㷨��C++�к��д˺������˴����������ʵ�ֹ���

int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int x, c;
		scanf("%d%d", &x, &c);
		add.push_back({ x,c });//��λ�����������add������
		alls.push_back(x);//�����ӷ���λ�ô���alls������
	}

	for (int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		query.push_back({ l,r });//������λ�ô���query������
		alls.push_back(l);//����߽�λ�ô���alls������
		alls.push_back(r);//���ұ߽�λ�ô���alls������
	}

	sort(alls.begin(), alls.end());//��alls�����е�λ�ý�������
	alls.erase(unique(alls), alls.end());
	/*
	��������alls����ȥ�أ��Ƚ��ظ�Ԫ�ؽ�������������ٽ���������Ԫ��ɾ����
	���˴�ʹ��C++�ĺ���unique����Ҫд�ɣ�alls.erase(unique(alls.begin(), alls.end()), alls.end());
	*/

	for (auto item:add)
	{
		int x = find(item.X);
		a[x] += item.Y;//ʹ��add�����е�λ�������������λ�ö�Ӧ��a������λ�ü��ϼ���
	}

	for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];//��a�������һάǰ׺���㷨

	for (auto item : query)
	{
		int l = find(item.X), r = find(item.Y);
		/*
		ʹ��query�����е�λ�ö�Ӧalls�е�λ�ã��ٶ�Ӧ��������е�ǰ׺�͵õ������
		*/
		printf("%d\n", s[r] - s[l - 1]);
	}

	return 0;
}