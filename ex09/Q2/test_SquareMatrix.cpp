#include <iostream>
#include <cassert>
#include "SquareMatrix.h"

using namespace std;

int main(void) {
    //Tests for int type and 2 dimensions
    SquareMatrix<int,2> A2; // A2 = I
    int coefficients2[2][2] = {{1,2},{3,4}};
    SquareMatrix<int,2> B2(coefficients2);

    SquareMatrix<int,2> C2 = A2 * B2;
    assert(C2 == B2);

    C2 += B2;
    C2 -= A2;
    assert(C2(0,0) == 1.0);
    assert(C2(1,1) == 7.0);
    
    SquareMatrix<int,2> D2 = -A2;
    assert(D2(0,0) == -1.0);
    assert(D2(1,1) == -1.0);


    //Tests for double type and 3 dimensions
    SquareMatrix<double,3> A3; // A3 = I
    double coefficients3[3][3] = {{1.0,2.0,3.0},{4.0,5.0,6.0},{7.0,8.0,9.0}};
    SquareMatrix<double,3> B3(coefficients3);

    SquareMatrix<double,3> C3 = A3 * B3;
    assert(C3 == B3);

    C3 += B3;
    C3 -= A3;
    assert(C3(0,0) == 1.0);
    assert(C3(1,1) == 9.0);
    assert(C3(2,2) == 17.0);

    SquareMatrix<double,3> D3 = -A3;
    assert(D3(0,0) == -1.0);
    assert(D3(1,1) == -1.0);
    assert(D3(2,2) == -1.0);

    cout << "Tests passed" << endl;

    return 0;
}