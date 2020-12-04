#ifndef MAT3X3_h
#define MAT3X3_h

#include <iostream>
#include <cmath>

using namespace std;

class Mat3x3 {
    public:
    Mat3x3();
    Mat3x3(double[3][3]);
    Mat3x3& operator+= (const Mat3x3&);
    Mat3x3& operator-= (const Mat3x3&);
    Mat3x3& operator*= (const Mat3x3&);
    const Mat3x3 operator-();
    double& operator() (int, int);
    const double& operator() (int, int) const;
    bool operator== (const Mat3x3&) const;
    friend ostream& operator<< (ostream& os, const Mat3x3& m);
    
    double entries[3][3];
};

const Mat3x3 operator+(const Mat3x3& ,const Mat3x3&);
const Mat3x3 operator-(const Mat3x3& ,const Mat3x3&);
const Mat3x3 operator*(const Mat3x3& ,const Mat3x3&);

#endif