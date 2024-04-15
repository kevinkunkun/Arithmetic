#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int h[N], ph[N], hp[N], cnt;

void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

void down(int x)
{
	int t = x;
	if (x * 2 <= cnt && h[x * 2] < h[t]) t = x * 2;
	if (x * 2 + 1 <= cnt && h[x * 2 + 1] < h[t]) t = x * 2 + 1;
	if (x != t)
	{
		heap_swap(x, t);
		down(t);
	}
}

void up(int x)
{
	while (x / 2 && h[x] < h[x / 2])
	{
		heap_swap(x, x / 2);
		x >>= 1;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m = 0;

	cin >> n;
	while (n--)
	{
		string op;
		int k, x;

		cin >> op;
		if (op == "I")
		{
			cin >> x;
			cnt++;
			m++;
			ph[m] = cnt, hp[cnt] = m;
			h[cnt] = x;
			up(cnt);
		}
		else if (op == "PM") cout << h[1] << endl;
		else if (op == "DM")
		{
			heap_swap(1, cnt);
			cnt--;
			down(1);
		}
		else if (op == "D")
		{
			cin >> k;
			k = ph[k];
			heap_swap(k, cnt);
			cnt--;
			up(k);
			down(k);
		}
		else
		{
			cin >> k >> x;
			k = ph[k];
			h[k] = x;
			up(k);
			down(k);
		}
	}

	return 0;
}