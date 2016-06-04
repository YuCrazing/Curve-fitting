#ifndef LEASTSQUARE_H_INCLUDED
#define LEASTSQUARE_H_INCLUDED

#include "Matrix.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
class LeastSquare {
    int n, order;
    double x[100], y[100], p[100];
    Matrix equations;

public:
    void init(double _eps);
    void solve();

    double phi(int pow, double x);
};

#endif // LEASTSQUARE_H_INCLUDED
