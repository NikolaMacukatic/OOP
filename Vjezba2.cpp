#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;



// PRVI ZADATAK


int* funk(int a)
{
	int* niz = new int[a];

	if (a >= 1) niz[0] = 1;
	if (a >= 2) niz[1] = 1;

	for (int i = 2; i < a; i++)
	{
		niz[i] = niz[i - 1] + niz[i - 2];


	}


	return niz;
}

// DRUGI ZADATAK


struct Vector
{
	int* el;  // Ovo triba bit niz
	int logv;
	int fizv;

};

Vector vector_new(int init)
{
	Vector v;
	v.el = new int[init];
	v.logv = 0;
	v.fizv = init;
	return v;
}

void vector_delete(Vector& v)
{
	delete[] v.el;
	v.el = nullptr;
	v.logv = 0;
	v.fizv = 0;
}

void vector_push_back(Vector& v, int broj)
{
	if (v.logv >= v.fizv)
	{
		int veciprostor = v.fizv * 2;
		int* noviNiz = new int[veciprostor];
		for (int i = 0; i < v.logv; i++)
		{
			noviNiz[i] = v.el[i];
		}
		delete[] v.el;
		v.el = noviNiz;
		v.fizv = veciprostor;

	}

	v.el[v.logv] = broj;
	v.logv++;

}

void vector_pop_back(Vector& v)
{
	if (v.logv > 0) v.logv--;
}

int vector_front(const Vector& v)
{
	return v.el[0];
}


int vector_back(const Vector& v)
{
	return v.el[v.logv - 1];
}

int vector_size(const Vector& v)
{
	return v.logv;
}


//TRECI ZADATAK 

double** alociraj_matricu(int m, int n) {
	double** A = new double* [m];     
	for (int i = 0; i < m; i++)
		A[i] = new double[n];        
	return A;
}


void dealociraj_matricu(double** A, int m) {
	for (int i = 0; i < m; i++)
		delete[] A[i];
	delete[] A;
}


void unos_matrice(double** A, int m, int n) {
	cout << "Unesite elemente matrice (" << m << "x" << n << "):\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "A[" << i << "][" << j << "] = ";
			cin >> A[i][j];
		}
	}
}


void generiraj_matricu(double** A, int m, int n, double a, double b) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			double r = (double)rand() / RAND_MAX; 
			A[i][j] = a + r * (b - a);            
		}
	}
}


void ispisi_matricu(double** A, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(10) << fixed << setprecision(4) << A[i][j] << " ";
		}
		cout << endl;
	}
}


double** zbroji_matrice(double** A, double** B, int m, int n) {
	double** C = alociraj_matricu(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			C[i][j] = A[i][j] + B[i][j];
	return C;
}


double** oduzmi_matrice(double** A, double** B, int m, int n) {
	double** C = alociraj_matricu(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			C[i][j] = A[i][j] - B[i][j];
	return C;
}


double** pomnozi_matrice(double** A, double** B, int m, int n, int p) {
	double** C = alociraj_matricu(m, p);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < p; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	return C;
}


double** transponiraj(double** A, int m, int n) {
	double** T = alociraj_matricu(n, m);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			T[j][i] = A[i][j];
	return T;
}


int main()
{
	//ZAD1
	int a;

	cout << "Unesi velicinu niza: ";
	cin >> a;

	int* niz = funk(a);

	cout << "Fibonacijev niz: " << endl;

	for (int i = 0; i < a; i++)
	{
		cout << niz[i] << endl;

	}
	delete[] niz;


	//ZAD2

	Vector v = vector_new(2);

	vector_push_back(v, 10);
	vector_push_back(v, 20);
	vector_push_back(v, 30);


	cout << "Prvi el: " << vector_front(v) << endl;
	cout << "Zadnji el: " << vector_back(v) << endl;
	cout << "Broj el: " << vector_size(v) << endl;

	vector_pop_back(v);
	cout << "Velicina je sad" << vector_size(v) << endl;
	cout << "Novi zadnji el: " << vector_back(v) << endl;


	vector_delete(v);


	//ZAD3

	srand(time(0)); 

	int m = 2, n = 3;
	double** A = alociraj_matricu(m, n);
	double** B = alociraj_matricu(m, n);

	generiraj_matricu(A, m, n, 0.0, 10.0);
	generiraj_matricu(B, m, n, 0.0, 10.0);

	cout << "Matrica A:\n";
	ispisi_matricu(A, m, n);

	cout << "\nMatrica B:\n";
	ispisi_matricu(B, m, n);

	double** Z = zbroji_matrice(A, B, m, n);
	cout << "\nA + B:\n";
	ispisi_matricu(Z, m, n);

	double** O = oduzmi_matrice(A, B, m, n);
	cout << "\nA - B:\n";
	ispisi_matricu(O, m, n);

	double** T = transponiraj(A, m, n);
	cout << "\nTransponirana matrica A^T:\n";
	ispisi_matricu(T, n, m);


	dealociraj_matricu(A, m);
	dealociraj_matricu(B, m);
	dealociraj_matricu(Z, m);
	dealociraj_matricu(O, m);
	dealociraj_matricu(T, n);





	return 0;
}











