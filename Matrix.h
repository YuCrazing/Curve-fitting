#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
class Matrix{
    int N;
    double a[100][100];
    double b[100];
    double x[2][100];
    double eps;

public:
    void init(int _N, double _a[0][100], double _b[], double _x[], double _eps);
    void showN();
    void showA();
    void showb();
    void showx(int type);
    void showEps();
    void show();

    double getEps();
    bool finish();

    void Recursion(int id, int type, double omega);
    void Jacobi();
    void Gauss_Seidel();
    double* SOR(double omega);

};
#endif // MATRIX_H_INCLUDED
