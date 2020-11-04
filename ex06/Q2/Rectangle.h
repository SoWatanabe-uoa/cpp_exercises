#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include "Shape2D.h"
#include "Point2D.h"

class Rectangle : public Shape2D {
    public:
    Rectangle(const Point2D&, float, float);

    std::string get_name() const override;

    float compute_area() const override;

    void translate(float tx, float ty) override;

    private:
    Point2D left_corner;
    float width;
    float height;
};

#endif