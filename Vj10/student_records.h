#ifndef STUDENT_RECORDS_H
#define STUDENT_RECORDS_H

#include <string>
#include <iostream>

using namespace std;

namespace student_records {

    struct Student {
        string ime;
        string prezime;
        int bodovi;
    };

    istream& operator>>(istream& is, Student& s);
    ostream& operator<<(ostream& os, const Student& s);

}

#endif
