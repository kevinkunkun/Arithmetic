#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(string state)
{
	unordered_map<string,int> d;//������ϣ��d
	queue<string> q;//��������q

	string end = "12345678x";//��������Ч��

	q.push(state);//����̬�������
	d[state] = 0;//����̬���̨֮��ı仯�����������Ϊ0

	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };//��ʼ���������ҵı�������
	while (q.size())
	{
		auto t = q.front();//ȡq���е���Ԫ��Ϊt
		q.pop();//������Ԫ��

		if (t == end) return d[t];//����ﵽ������Ч����ֱ�ӷ��ش�ʱ�ı任����

		int distance = d[t];//����t��Ӧ��ϣ���е�ֵȡ������ֵ��distance
		int k = t.find('x');//���ַ������ҵ�x�Ķ�Ӧ�±�
		int x = k / 3, y = k % 3;//x��y�ֱ��ʾ'x'��3*3�����еĺ�������������

		for (int i = 0; i < 4; i++)//�����ĸ�����
		{
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && a < 3 && b >= 0 && b < 3)
			{
				swap(t[a * 3 + b], t[k]);//�����������������������ַ����еĶ�Ӧλ��
				if (!d.count(t))
				{
					d[t] = distance + 1;//����ʱ��tδ�ڹ�ϣ���д��ڹ���ʹ���Ӧ�ı仯ֵ��һ
					q.push(t);//�����������н�����һ�εı���
				}
				swap(t[a * 3 + b], t[k]);//��ԭ������λ�ã�����ʣ������ı���
			}
		}
	}

	return -1;//������ѭ����ȫ��δ�ﵽ����Ч��˵�����ܱ仯������Ч��������-1
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	char s[2];//�������ո�

	string state;

	//�����ַ���
	for (int i = 0; i < 9; i++)
	{
		cin >> s;
		state += *s;
	}

	cout << bfs(state) << endl;

	return 0;
}