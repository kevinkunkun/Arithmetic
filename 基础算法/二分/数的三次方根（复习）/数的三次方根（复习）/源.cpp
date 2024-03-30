#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	double n;
	cin >> n;

	double l = -100000, r = 100000;
	while (r - l > 1e-8)
	{
		double mid = (l + r) / 2;
		if (mid * mid * mid >= n) r = mid;
		else l = mid;
	}

	printf("%lf", l);
}