#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

int ogr(int x, int low = 0, int high = 100)
{
    if (x < low) return low;
    else if (x > high) return high;
    else return x;
}

double ogr(double x, double low = 0.0, double high = 1.0)
{
    if (x < low) return low;
    else if (x > high) return high;
    else return x;
}

int& at(int ary[], int i)
{
    return ary[i];

}

int main()
{       
    
    //ZAD2
    int a;
    double b;

    cout << "Unesi int i double b: " << endl;
    cin >> a;
    cin >> b;

    cout << "Broj " << a << " vraca: " << ogr(a) << endl;
    cout << "broj" << b << " vraca: " << ogr(b) << endl;

    cout << "ogr -5 = " << ogr(-5) << endl;
    cout << "ogr 120 = " << ogr(120) << endl;
    cout << "ogr -1.5 = " << ogr(1.5) << endl;


    //ZAD3

    string s;
    cin.get();
    cout << "Unesi string" << endl;
    getline(cin, s);

    for (char& c : s)
    {
        if (isalpha(c))
        {
            c = toupper(c);
        }

        else if (isdigit(c))
        {
            c = '*';

        }
        else if (c == ' ' || c == '\t')
        {
            c = '_';
        }

    }

    cout << "Novi string je: " << s << endl;


    //ZAD4

    int niz[] = { 1,2,3,4,5 };
    int duzina = 5;

    at(niz, 2) += 1;

    cout << "Promjenjeni niz glasi: ";
    for (int i = 0; i < duzina; i++)
    {
        cout << niz[i];
    }
    cout << endl;

    at(niz, 1) = 99;
    at(niz, 4)++;


    cout << "Promjenjeni niz glasi: ";
    for (int i = 0; i < duzina; i++)
    {
        cout << niz[i];
    }
    cout << endl;

    // ZAD1


    bool flag;
    cout << "Unesi " << true << " - " << false << ": ";
    cin >> flag;
    cout << boolalpha << flag << endl;

    int num = 255;
    cout << "hex " << hex << num << endl;
    cout << "dec " << dec << num << endl;
    cout << "oct " << oct << num << endl;

    bool flag2;
    cout << "Unesi " << true << " - " << false << ": ";
    cin >> flag2;
    cout << noboolalpha << flag2 << endl;

    double pi = 3.141592;
    cout << "pi = " << scientific << uppercase;
    cout << setprecision(7) << setw(20);
    cout << setfill('0');
    cout << pi << endl;


    return 0;
}
