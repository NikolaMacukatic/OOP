#include <iostream>
#include <iomanip>
using namespace std;


int ogr(int x, int low = 0, int high = 100)
{
	if (x <= low) return low;
	else return high;

}

double ogr(double x, double low = 0.0, double high = 1.0)
{
	if (x <= low) return low;
	else return high;

}

int main()
{
	int a;
	double b;

	cout << "Unesi prvo int a pa double b" << endl;
	cin >> a;
	cin >> b;
	cout << "unutar intervala broj " << a << "vraca: " << ogr(a) << endl;
	cout << "unutar intervala broj " << b << "vraca: " << ogr(b) << endl;

}





/*
int main()
{
	bool flag;
	std::cout << "unesi " << true << " - " << false << std::endl;
	std::cin >> flag;
	std::cout << std::boolalpha << flag << std::endl;

	int a = 255;
	std::cout << "hex " << std::hex << a << std::endl;
	std::cout << "dec " << std::dec << a << std::endl;
	std::cout << "oct " << std::oct << a << std::endl;

	double pi = 3.141592;
	std::cout << "pi = " << std::scientific << std::uppercase;
	std::cout << std::setprecision(7) << std::setw(20);
	std::cout << std::setfill('0');
	std::cout << pi << std::endl;

	bool flag2;
	cout << "unesi " << true << " - " << false << endl;
	cin >> flag;
	cout << noboolalpha << flag << endl;

}
*/