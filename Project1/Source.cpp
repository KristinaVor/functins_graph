#include <iostream>
#include <fstream>

using namespace std;

long double f(long double x)
{
	return x * x * x * x * x * x;
}

long double diff(long double f(long double), long double x0, long double dx)
{
	long double tmp = (f(x0 + dx) - f(x0 - dx)) / (2 * dx);

	return tmp;
}

long double diff_l(long double f(long double), long double x0, long double dx)
{
	long double tmp = (f(x0) - f(x0 - dx)) / (dx);

	return tmp;
}

long double diff_r(long double f(long double), long double x0, long double dx)
{
	long double tmp = (f(x0 + dx) - f(x0 - dx)) / (dx);

	return tmp;
}

int main()
{
	long double x0 = 2.0;
	long double dx = 0.001;

	cout << diff(f, x0, dx) << endl;
	
	ofstream outF("data.txt");
	outF << diff(f, x0, dx);
	outF.close();

	ifstream inF("data.txt");

	int a = {};
	inF >> a;
	cout << a;

	return 0;
}
