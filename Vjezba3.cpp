#include<iostream>
#include <cstddef>
#include <vector>
#include <string>
using namespace std;


//ZADATAK 1
/*
void sortt(int[], size_t, bool (*cmp)(int, int));



inline bool asc(int a, int b){return a < b;}


inline bool desc(int a, int b){return a > b;}


void sortt(int niz[],size_t size, bool (*cmp)(int, int))
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (cmp(niz[j], niz[i]))
			{
				int temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}

}

//ZADATAK2


template <typename T>
inline bool asc(T a, T b) { return a < b; }

template <typename T>
inline bool desc(T a, T b) { return a > b; }

template <typename T>
void sortt(T niz[], size_t size, bool (*cmp)(T, T))
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (cmp(niz[j], niz[i]))
			{
				T temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}

}

int main()
{


	//ZAD1
	int niz[] = { 5,2,9,1,7 };
	size_t n = sizeof(niz) / sizeof(niz[0]);

	cout << "Niz glasi: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << niz[i] << endl;
	}

	cout << "--------------------------------------" << endl;

	cout << "Asc glasi: " << endl;
	sortt(niz, n, asc);

	for (int i = 0; i < n; i++)
	{
		cout << niz[i] << endl;
	}
	cout << "--------------------------------------" << endl;

	cout << "Desc glasi: " << endl;
	sortt(niz, n, desc);

	for (int i = 0; i < n; i++)
	{
		cout << niz[i] << endl;
	}
	cout << "--------------------------------------" << endl;


	//ZAD2

	double nizD[] = { 3.14, 2.71, 1.41, 0.577, 4.669 };
	size_t m = sizeof(nizD) / sizeof(nizD[0]);

	

	sortt(nizD, m, asc);
	cout << "Uzlazno (double): ";
	for (size_t i = 0; i < m; ++i)
	cout << nizD[i] << " ";
	cout <<endl;

	sortt(nizD, m, desc);
	cout << "Silazno (double): ";
	for (std::size_t i = 0; i < m; ++i)
	cout << nizD[i] << " ";
	cout <<endl;

	//ZAD3

	vector<int> niz1 = { 1,2,3,4,5,6 };


	auto parni = [](int x) {return x % 2 == 0; };
	auto neparni = [](int x) {return x % 2 != 0; };
	auto udvostruci = [](int x) {return x*2; };
	auto prepolovi = [](int x) {return x/2; };

	int suma = 0;
	int produkt = 1;
	int prag = 2;

	auto dodajuSumu = [&suma](int x) {suma += x; };
	auto dodajuProdukt = [&produkt](int x) {produkt += x; };
	auto dodajakoprag = [prag, &suma](int x) { if (prag > x) suma += x; };

	cout << "1) Parne prepolovi, neparne udvostruci:\n";
	for (auto& x : niz1) {
		if (parni(x))
			x = prepolovi(x);
		else
			x = udvostruci(x);
		cout << x << " ";
	}
	cout << "\n";

	for (int x : niz1) {
		dodajuSumu(x);
		dodajuProdukt(x);
	}
	cout << "2) Suma = " << suma << ", Produkt = " << produkt << "\n";

	// --- FUNKCIJA 3: suma vecih od praga ---
	for (int x : niz1)
		dodajakoprag(x);
	cout << "3) Suma brojeva vecih od " << prag << " = " << suma << "\n";

	
	return 0;

	*/


//ZAD4

struct Student {

	string ime;
	string JMBAG;
	int godina;
	int ects;
	double prosjek;
};

void filtriraj(Student*studenti, size_t vel, void(*akcija)(Student&), bool(*filter)(Student&))
{
	for (size_t i = 0; i < vel; i++)
	{
		if (filter(studenti[i]))
		{
			akcija(studenti[i]);
		}
	}
}


void ispis(Student& s)
{

	cout << "Ime: " << s.ime<<endl;
	cout << "JMBAG: " << s.JMBAG << endl;
	cout << "Godina: " << s.godina << endl;
	cout << "ECTS: " << s.ects << endl;
	cout << "Prosjek: " << s.prosjek << endl;
	cout << "-----------------------------------" << endl;
	


}

void povecaj(Student& s)
{
	s.godina++;
}

int main()
{
	Student studenti[] = {

		{"Marko","001",1,5,3.2},
		{ "Ana","002",1,0,3.8 },
		{ "Ivan","003",2,50,3.1 },
		{ "Petra","004",3,60,4.2 },
		{ "Luka","005",1,30,3.6 }
	};

	size_t vel = sizeof(studenti) / sizeof(studenti[0]);

	cout << "Studenati koji su polozili bar jedan ispit: " << endl;
	auto uvjet1 = [](Student& s) { return s.godina == 1 && s.ects > 0; };
	filtriraj(studenti, vel, ispis, uvjet1);

	cout << "Studenati koji imaju prosjek veci od 3.5: " << endl;
	auto uvijet2 = [](Student& s) {return s.prosjek > 3.5; };
	filtriraj(studenti, vel, ispis, uvijet2);

	cout << "Podizanje godine studentima s minimalno 45 ects " << endl;
	auto uvijet3 = [](Student& s) {return s.ects >= 45; };
	filtriraj(studenti, vel, povecaj, uvijet3);

return 0;
}
