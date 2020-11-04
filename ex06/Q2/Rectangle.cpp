#include "Rectangle.h"

Rectangle::Rectangle(const Point2D& p, float w, float h): left_corner(p), width(w), height(h) {}

std::string Rectangle::get_name() const {
    return "rectangle";
}

float Rectangle::compute_area() const {
    return width * height;
}

void Rectangle::translate(float tx, float ty) {
    left_corner.set_x(left_corner.get_x() + tx);
    left_corner.set_y(left_corner.get_y() + ty);
}
