#ifndef SHAPE2D_H
#define SHAPE2D_H

#include <string>

class Shape2D{
    public:
    virtual ~Shape2D(){}
    virtual std::string get_name() const = 0;
    virtual float compute_area() const = 0;
    virtual void translate(float tx, float ty) = 0;
};

#endif