#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <vector>
#include <iostream>

using namespace std;

namespace math_utils {

    struct Point {
        double x;
        double y;
    };

    double distance(const Point& a, const Point& b);
    Point centroid(const vector<Point>& points);

    istream& operator>>(istream& is, Point& p);
    ostream& operator<<(ostream& os, const Point& p);

}

#endif
