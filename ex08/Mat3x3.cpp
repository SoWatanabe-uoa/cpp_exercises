#include "Mat3x3.h"

Mat3x3::Mat3x3(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            entries[i][j] = (i==j) ? 1.0 : 0.0;
        }
    }
}

Mat3x3::Mat3x3(double other_entries[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            entries[i][j] = other_entries[i][j];
        }
    }
}

Mat3x3& Mat3x3::operator+= (const Mat3x3& other) {
    *this = *this + other;
    return *this;
}

Mat3x3& Mat3x3::operator-= (const Mat3x3& other) {
    *this = *this - other;
    return *this;
}

Mat3x3& Mat3x3::operator*=(const Mat3x3& other) {
    *this = (*this) * (other);
    return *this;
}


const Mat3x3 Mat3x3::operator-() {
    Mat3x3 result;
    for (int i=0; i<3; ++i){
        for (int j=0; j<3; ++j){
            result.entries[i][j] = -entries[i][j];
        }
    }
    return result;
}

const double& Mat3x3::operator() (const int& i,const int& j) const {
    return entries[i][j];
}

bool Mat3x3::operator== (const Mat3x3& other) const {
    const double eps = 1e-5;
    bool equal_flag = true;
    for (int i=0; i<3; ++i){
        for (int j=0; j<3; ++j){
            if( !(std::fabs(entries[i][j] - other.entries[i][j]) < eps) ) equal_flag = false;
        }
    }
    return equal_flag;
}

ostream& operator<< (ostream& os, const Mat3x3& m) {
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            os << m.entries[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

const Mat3x3 operator+(const Mat3x3& m1,const Mat3x3& m2){
    Mat3x3 result;
    for (int i=0; i < 3; ++i){
        for (int j=0; j < 3; ++j){
            result.entries[i][j] = m1.entries[i][j] + m2.entries[i][j];
        }
    }
    return result;
}

const Mat3x3 operator-(const Mat3x3& m1,const Mat3x3& m2){
    Mat3x3 result;
    for (int i=0; i < 3; ++i){
        for (int j=0; j < 3; ++j){
            result.entries[i][j] = m1.entries[i][j] - m2.entries[i][j];
        }
    }
    return result;
}

const Mat3x3 operator*(const Mat3x3& m1,const Mat3x3& m2){
    Mat3x3 result;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            result.entries[i][j] = 0.0;
            for (int k=0; k<3; ++k) {
                result.entries[i][j] += m1.entries[i][k] * m2.entries[k][j];
            }
        }
    }
    return result;
}