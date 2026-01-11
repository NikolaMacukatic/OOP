#include "student_records.h"

using namespace std;

namespace student_records {

    istream& operator>>(istream& is, Student& s)
    {
        is >> s.ime >> s.prezime >> s.bodovi;
        return is;
    }

    ostream& operator<<(ostream& os, const Student& s)
    {
        os << s.ime << " " << s.prezime << " " << s.bodovi;
        return os;
    }

}
