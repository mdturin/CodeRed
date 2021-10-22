#include "bits/stdc++.h"
using namespace std;

const double eps = 1e-8;

bool isEquals(double l, double r) {return (fabs(l - r) < eps);}

bool isLess(double l, double r, bool orequal = false) {
    if (fabs(l - r) < eps)
        return (orequal);
    return (l < r);
}

bool isGreater(double l, double r, bool orequal = false) {
    if (fabs(l - r) < eps)
        return (orequal);
    return (l > r);
}

int main(int argc, const char** argv) {

    /**
        (a == b) -> isEqual(a, b)
        (a <  b) -> isLess(a, b)
        (a <= b) -> isLess(a, b, true)
        (a >  b) -> isGreater(a, b)
        (a >= b) -> isGreater(a, b, true)
        (a != b) -> ! isEqual(a, b)
    */

    return 0;
}