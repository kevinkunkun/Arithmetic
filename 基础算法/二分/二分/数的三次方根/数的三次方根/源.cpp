#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	double x;
	cin >> x;
	
	double l = -100, r = 100;
	while (r - l > 1e-8)
	{
		double mid = (l + r) / 2;
		if (mid * mid * mid >= x) r = mid;
		else l = mid;
	}
	printf("%lf", l);

	return 0;
}