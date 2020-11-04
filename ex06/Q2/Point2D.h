#ifndef POINT2D_H
#define POINT2D_H

class Point2D{
    public:
    Point2D(float x=0.0f,float y=0.0f);

    float get_x() const;
    float get_y() const;
    void set_x(float);
    void set_y(float);
    
    private:
    float _x;
    float _y;
};

#endif