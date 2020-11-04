#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include "Shape2D.h"
#include "Point2D.h"

class Circle : public Shape2D {
    public:
    Circle(const Point2D&, float);

    std::string get_name() const override;

    float compute_area() const override;

    void translate(float tx, float ty) override;

    private:
    Point2D center;
    float radius;
};

#endif