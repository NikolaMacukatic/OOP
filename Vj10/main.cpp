#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <fstream>
#include "math_utils.h"
#include "student_records.h"

using namespace std;
using namespace math_utils;
using namespace student_records;

bool is_power_of_two(int x)
{
    return x > 0 && (x & (x - 1)) == 0;
}

int bodovi_u_ocjenu(int bodovi)
{
    if (bodovi < 40) return 1;
    if (bodovi < 55) return 2;
    if (bodovi < 70) return 3;
    if (bodovi < 85) return 4;
    return 5;
}

int main()
{
    vector<int> brojevi{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 16, 21 };

    auto prvi_neparni = find_if(brojevi.begin(), brojevi.end(), [](int x) {
        return x % 2 != 0;
        });

    int broj_neparnih = count_if(brojevi.begin(), brojevi.end(), [](int x) {
        return x % 2 != 0;
        });

    int suma_neparnih = accumulate(brojevi.begin(), brojevi.end(), 0, [](int acc, int x) {
        return x % 2 != 0 ? acc + x : acc;
        });

    double prosjek_neparnih = broj_neparnih == 0
        ? 0
        : static_cast<double>(suma_neparnih) / broj_neparnih;

    replace_if(brojevi.begin(), brojevi.end(), is_power_of_two, 2);

    vector<int> parni, neparni;

    copy_if(brojevi.begin(), brojevi.end(), back_inserter(parni), [](int x) {
        return x % 2 == 0;
        });

    copy_if(brojevi.begin(), brojevi.end(), back_inserter(neparni), [](int x) {
        return x % 2 != 0;
        });

    sort(parni.begin(), parni.end());
    sort(neparni.begin(), neparni.end());

    copy(parni.begin(), parni.end(), ostream_iterator<int>(cout, " "));
    copy(neparni.begin(), neparni.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    ifstream pointsFile("points.txt");
    vector<Point> points((istream_iterator<Point>(pointsFile)), istream_iterator<Point>());

    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return distance(a, Point{ 0, 0 }) < distance(b, Point{ 0, 0 });
        });

    int firstQuadrant = count_if(points.begin(), points.end(), [](const Point& p) {
        return p.x > 0 && p.y > 0;
        });

    Point c = centroid(points);

    transform(points.begin(), points.end(), points.begin(), [](Point p) {
        p.x += 5;
        p.y += 3;
        return p;
        });

    points.erase(remove_if(points.begin(), points.end(), [](const Point& p) {
        return p.x < 0 && p.y < 0;
        }), points.end());

    copy(points.begin(), points.end(), ostream_iterator<Point>(cout, "\n"));

    ifstream studentsFile("studenti.txt");
    vector<Student> studenti((istream_iterator<Student>(studentsFile)), istream_iterator<Student>());

    studenti.erase(remove_if(studenti.begin(), studenti.end(), [](const Student& s) {
        return s.bodovi < 40;
        }), studenti.end());

    transform(studenti.begin(), studenti.end(), studenti.begin(), [](Student s) {
        s.bodovi = bodovi_u_ocjenu(s.bodovi);
        return s;
        });

    double prosjek_ocjena = accumulate(studenti.begin(), studenti.end(), 0.0,
        [](double acc, const Student& s) {
            return acc + static_cast<double>(s.bodovi);
        }) / studenti.size();

    sort(studenti.begin(), studenti.end(), [](const Student& a, const Student& b) {
        return a.prezime < b.prezime;
        });

    for (const auto& s : studenti)
        cout << s.ime << " " << s.prezime << " " << s.bodovi << "\n";

    cout << prosjek_ocjena << "\n";
}
