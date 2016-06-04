#include "LeastSquare.h"

void LeastSquare::init(double _eps){
    scanf("%d", &n);

    for(int i = 0; i < n; i ++) scanf("%lf", &x[i]);
    for(int i = 0; i < n; i ++) scanf("%lf", &y[i]);
    for(int i = 0; i < n; i ++) scanf("%lf", &p[i]);
    scanf("%d", &order);

    int _N = order;
    double _a[100][100], _x[100], _b[100];

    //
    for(int i = 0; i < order; i ++) _x[i] = 0.0;
    //

    for(int i = 0; i < order; i ++){
        for(int j = 0; j < order; j ++){
            _a[i][j] = 0;
            for(int _i = 0; _i < n; _i ++) _a[i][j] += p[_i] * phi(i, x[_i]) * phi(j, x[_i]);
        }
    }
    for(int i = 0; i < order; i ++){
        _b[i] = 0;
        for(int j = 0; j < n; j ++) _b[i] += p[j] * phi(i, x[j]) * y[j];
    }
    equations.init(_N, _a, _b, _x, _eps);
}

void LeastSquare::solve(){
    double* a = equations.SOR(1.5);
    printf("\n\nf(x) = ");
    for(int i = 0; i < order; i ++) {
        if(i == 0) printf("%.10f", a[i]);
        else{
            if(a[i] > 0) printf(" + %.10f x^%d", a[i], i);
            else printf(" - %.10f x^%d", -a[i], i);
        }
    }
    printf("\n\nx\t\tf(x)\t\ty\t\t|f(x) - y|\n");
    for(int i = 0; i < n ; i ++){
        double fx = 0;
        for(int j = 0; j < order; j ++) fx += a[j] * phi(j, x[i]);
        printf("%f\t%f\t%f\t%f\n", x[i], fx, y[i], fx - y[i] > 0 ? fx - y[i] : y[i] - fx);

    }
}

double LeastSquare::phi(int pow, double x){
    double res = 1;
    for(int i = 0; i < pow; i ++) res *= x;
    return res;
}
