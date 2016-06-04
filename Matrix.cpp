#include "Matrix.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

void Matrix::init(int _N, double _a[][100], double _b[], double _x[], double _eps) {
    N = _N;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++)
            a[i][j] = _a[i][j];

        b[i] = _b[i];
        x[0][i] = _x[i];
        x[1][i] = x[0][i];
    }
    eps = _eps;

//    printf("N : %d, eps : %f\n\n", N, eps);
//    for(int i = 0; i < N; i ++)
//        for(int j = 0; j < N; j ++)
//            printf((j == N - 1)? "%f\n" : "%f ", a[i][j]);
//    printf("b:\n");
//    for(int i = 0; i < N; i ++) printf((i == N - 1) ? "%f\n" : "%f ", b[i]);
//    printf("x:\n");
//    for(int i = 0; i < N; i ++) printf((i == N - 1) ? "%f\n" : "%f ", x[0][i]);

}

void Matrix::showN() {
    printf("N = %d\n", N);
}

void Matrix::showA() {
    printf("A:\n");
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            printf((j == N-1)?"%.3f\n":"%.3f ", a[i][j]);
}

void Matrix::showb() {
    printf("b:\n");
    for(int i = 0; i < N; i++) printf("%.3f\n", b[i]);
}

void Matrix::showx(int type) {
//    if(type > 1 || type < 0) return printf("Parameter [int type] is invalid in function showx().\n") * 0;
    printf("x:\n");
    for(int i = 0; i < N; i++) printf("x%d = %.10f\n", i, x[type][i]);
//    for(int i = 0; i < N; i++) printf("x%d = %.3f\n", i, x[1][i]);
}

void Matrix::showEps() {
    printf("Epsilon = %f\n", eps);
}

void Matrix::show() {
    printf("--\nN = %d:\n", N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) printf("%.3f ", a[i][j]);
        printf("%.3f\n", b[i]);
    }
}

double Matrix::getEps() {
    return eps;
}
bool Matrix::finish() {
    double R = 0;
    for(int i = 0; i < N; i++) R = max(R, abs(x[0][i] - x[1][i]));
    return R <= eps;
}

// Cal x, last recursion result store in x[0], new recursion result store in x[1].
void Matrix::Recursion(int id, int type, double omega) {
//    if(type < 0 || type > 2) return printf("Parameter [int type] is invalid in function Recursion().\n") * 0;
    if(a[id][id] == 0) {
        printf("Div by 0. a[%d][%d] == 0.\n", id, id);
        return ;
    }
    double sum = 0;
    for(int i = 0; i < N ; i++) if(i != id) sum += a[id][i] * x[0][i];
    if(type == 0) x[1][id] = (b[id] - sum) / a[id][id];
    else if(type == 1) x[0][id] = (b[id] - sum) / a[id][id];
    else if(type == 2) x[0][id] = (1 - omega) * x[0][id] + omega * (b[id] - sum) / a[id][id];
    //printf("x[%d]:%.3f ", id, x[1][id]);
}

void Matrix::Jacobi() {
    do {
        for(int i = 0; i < N; i++) Recursion(i, 0, 0);
        for(int i = 0; i < N; i++) swap(x[0][i], x[1][i]);

    } while(!finish());
    showx(0);
}

void Matrix::Gauss_Seidel() {
    do {
        for(int i = 0; i < N; i++) x[1][i] = x[0][i];
        for(int i = 0; i < N; i++) Recursion(i, 1, 0);
    } while(!finish());
    showx(0);
}
double* Matrix::SOR(double omega) {
    do {
        for(int i = 0; i < N; i++) x[1][i] = x[0][i];
        for(int i = 0; i < N; i++) Recursion(i, 2, omega);
    } while(!finish());
    return x[0];
//    showx(0);
}




