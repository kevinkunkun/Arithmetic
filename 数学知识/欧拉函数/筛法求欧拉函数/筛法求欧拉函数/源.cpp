#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//�������Ķ��壺���������û�г���1���������������������������Ϊ������
using namespace std;

typedef long long LL;//N̫���˻ᱬint(0--2^31-1)������long long��0--2^63-1��

const int N = 1e6 + 10;

int primes[N], cnt;//�������飬����������
int euler[N];//ŷ����������
bool st[N];//�ж�������״̬���飬trueΪ��������falseΪ����

//ͨ������ɸ�ķ�ʽ��ŷ������
void get_euler(int n)
{
	euler[1] = 1;//1��ŷ������Ϊ1
	for (int i = 2; i <= n; i++)
	{
		if (!st[i])
		{
			primes[cnt++] = i;
			euler[i] = i - 1;
		}
		for (int j = 0; primes[j] <= n / i; j++)
		{
			int t = primes[j] * i;
			st[t] = true;
			if (i % primes[j] == 0)
			{
				//���������i������������ôԭŷ��������euler[i]����һ�����ڣ�1-1/primes[j]),��ֱ�ӳ���primes[j]����
				euler[t] = euler[i] * primes[j];
				break;//primes[j]Ϊi����С������ʱ����ѭ��
			}

			//�����������i������������ô����Ҫ��ԭŷ������(euler[i])�Ļ����ϳ���primes[j]����Ҫ���ϣ�1-1/primes[j]),�����ߺϲ��õ���primes[j]-1)
			else euler[t] = euler[i] * (primes[j] - 1);��
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	get_euler(n);//ŷ������

	LL res = 0;
	for (int i = 1; i <= n; i++) res += euler[i];//��1��n�ۼӵõ�ÿ������ŷ������֮��

	cout << res << endl;

	return 0;
}