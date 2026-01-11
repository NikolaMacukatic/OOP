#include "math_utils.h"
#include <numeric>
#include <cmath>

using namespace std;

namespace math_utils {

    double distance(const Point& a, const Point& b)
    {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    Point centroid(const vector<Point>& points)
    {
        Point sum = accumulate(points.begin(), points.end(), Point{ 0, 0 },
            [](Point acc, const Point& p) {
                acc.x += p.x;
                acc.y += p.y;
                return acc;
            });

        return {
            static_cast<double>(sum.x / points.size()),
            static_cast<double>(sum.y / points.size())
        };
    }

    istream& operator>>(istream& is, Point& p)
    {
        is >> p.x >> p.y;
        return is;
    }

    ostream& operator<<(ostream& os, const Point& p)
    {
        os << p.x << " " << p.y;
        return os;
    }

}
