#include "Point2D.h"

Point2D::Point2D(float x, float y): _x(x),_y(y) {}

float Point2D::get_x() const{
    return _x;
}

float Point2D::get_y() const{
    return _y;
}

void Point2D::set_x(float x){
    _x = x;
}

void Point2D::set_y(float y){
    _y = y;
}