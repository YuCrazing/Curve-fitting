#include "LeastSquare.h"
int main(){

    freopen("data.txt", "r", stdin);

    LeastSquare LS;
    LS.init(0.000000001);   // epsilon
    LS.solve();
    return 0;
}
