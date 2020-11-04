#include "Circle.h"

Circle::Circle(const Point2D& c, float r): center(c), radius(r) {}

std::string Circle::get_name() const {
    return "circle";
}

float Circle::compute_area() const {
    const float PI = 3.141593f;
    return radius * radius * PI;
}

void Circle::translate(float tx, float ty) {
    center.set_x(tx);
    center.set_y(ty);
}