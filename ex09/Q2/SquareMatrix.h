#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include <iostream>
#include <cmath>

using namespace std;

template <typename T, int N>
class SquareMatrix {
    public:
    SquareMatrix();
    SquareMatrix(T[N][N]);
    SquareMatrix& operator+= (const SquareMatrix&);
    SquareMatrix& operator-= (const SquareMatrix&);
    SquareMatrix& operator*= (const SquareMatrix&);
    const SquareMatrix operator-();
    T& operator() (int, int);
    bool operator== (const SquareMatrix&) const;
    //friend ostream& operator<<<T,N> (ostream&, const SquareMatrix&);

    T entries[N][N];
};

template <typename T, int N>
const SquareMatrix<T,N> operator+(const SquareMatrix<T,N>& ,const SquareMatrix<T,N>&);
template <typename T, int N>
const SquareMatrix<T,N> operator-(const SquareMatrix<T,N>& ,const SquareMatrix<T,N>&);
template <typename T, int N>
const SquareMatrix<T,N> operator*(const SquareMatrix<T,N>& ,const SquareMatrix<T,N>&);

#endif