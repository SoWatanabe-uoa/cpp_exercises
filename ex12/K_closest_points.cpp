#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    Point() : x(0.0), y(0.0), z(0.0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    double x, y, z;
};

class Compare{
    public:
    bool operator()(const Point& p1, const Point& p2){
        return ((p1.x)*(p1.x)+(p1.y)*(p1.y)+(p1.z)*(p1.z))
        < ((p2.x)*(p2.x)+(p2.y)*(p2.y)+(p2.z)*(p2.z));
    }
};

const vector<Point> find_k_closest(const int& k, const vector<Point>& points){
    priority_queue<Point,vector<Point>, Compare > pq;
    vector<Point>::const_iterator cvit;
    for (cvit = points.cbegin(); cvit != points.cend(); ++cvit){
        pq.push(*cvit);
    }
    vector<Point> result;
    for (cvit = result.cbegin(); cvit != result.cbegin() + k; ++cvit){
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}

int main(void) {
    vector<Point> points;
    points.push_back(Point(1.0,2.0,3.0));
    points.push_back(Point(5.0,5.0,5.0));
    points.push_back(Point(0.0,2.0,1.0));
    points.push_back(Point(9.0,2.0,1.0));
    points.push_back(Point(1.0,2.0,1.0));
    points.push_back(Point(2.0,2.0,1.0));

    vector<Point> closest = find_k_closest(3, points);
    /*for (size_t i = 0; i < 3; ++i) {
    cout << closest[i].x << "," << closest[i].y << "," 
                << closest[i].z << endl;
    }*/

}