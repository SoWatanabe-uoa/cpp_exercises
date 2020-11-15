#include "SquareMatrix.h"

template <typename T, int N>
SquareMatrix<T,N>::SquareMatrix(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            entries[i][j] = (i==j) ? 1.0 : 0.0;
        }
    }
}

template <typename T, int N>
SquareMatrix<T,N>::SquareMatrix(T other_entries[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            entries[i][j] = other_entries[i][j];
        }
    }
}

template <typename T, int N>
SquareMatrix<T,N>& SquareMatrix<T,N>::operator+= (const SquareMatrix& other) {
    *this = *this + other;
    return *this;
}

template <typename T, int N>
SquareMatrix<T,N>& SquareMatrix<T,N>::operator-= (const SquareMatrix& other) {
    *this = *this - other;
    return *this;
}

template <typename T, int N>
SquareMatrix<T,N>& SquareMatrix<T,N>::operator*= (const SquareMatrix& other) {
    *this = (*this) * (other);
    return *this;
}

template <typename T, int N>
const SquareMatrix<T,N> SquareMatrix<T,N>::operator-() {
    SquareMatrix result;
    for (int i=0; i<3; ++i){
        for (int j=0; j<3; ++j){
            result.entries[i][j] = -entries[i][j];
        }
    }
    return result;
}

template <typename T, int N>
T& SquareMatrix<T,N>::operator() (int i, int j){
    return entries[i][j];
}

template <typename T, int N>
bool SquareMatrix<T,N>::operator== (const SquareMatrix& other) const {
    const double eps = 1e-5;
    bool equal_flag = true;
    for (int i=0; i<N; ++i){
        for (int j=0; j<N; ++j){
            if( !(fabs(entries[i][j] - other.entries[i][j]) < eps) ) equal_flag = false;
        }
    }
    return equal_flag;
}

/*
template <typename T, int N>
ostream& operator<< (ostream& os, const SquareMatrix<T,N>& m) {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            os << m.entries[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
*/

template <typename T, int N>
const SquareMatrix<T,N> operator+(const SquareMatrix<T,N>& m1,const SquareMatrix<T,N>& m2){
    SquareMatrix<T,N> result;
    for (int i=0; i < N; ++i){
        for (int j=0; j < N; ++j){
            result.entries[i][j] = m1.entries[i][j] + m2.entries[i][j];
        }
    }
    return result;
}

template <typename T, int N>
const SquareMatrix<T,N> operator-(const SquareMatrix<T,N>& m1,const SquareMatrix<T,N>& m2){
    SquareMatrix<T,N> result;
    for (int i=0; i < N; ++i){
        for (int j=0; j < N; ++j){
            result.entries[i][j] = m1.entries[i][j] - m2.entries[i][j];
        }
    }
    return result;
}

template <typename T, int N>
const SquareMatrix<T,N> operator*(const SquareMatrix<T,N>& m1,const SquareMatrix<T,N>& m2){
    SquareMatrix<T,N> result;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            result.entries[i][j] = 0.0;
            for (int k=0; k<3; ++k) {
                result.entries[i][j] += m1.entries[i][k] * m2.entries[k][j];
            }
        }
    }
    return result;
}