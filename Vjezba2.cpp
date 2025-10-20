#include <iostream>
using namespace std;



// PRVI ZADATAK


int *funk(int n)
{
	int* niz = new int[n];

	if (n >= 1) niz[0] = 1;
	if (n >= 2) niz[1] = 1;

	for (int i = 2;i<n;i++)
	{
		niz[i] = niz[i - 1] + niz[i - 2];
	
	
	}


	return niz;
}


int main()
{
	int n;
	
	cout << "Unesi velicinu niza: ";
	cin >> n;

	int* niz = funk(n);

	cout << "Fibonacijev niz: " << endl;
	
	for (int i = 0; i < n; i++)
	{
		cout << niz[i] << endl;

	}
	delete[] niz;
	return 0;
}




//DRUGI ZADATAK

