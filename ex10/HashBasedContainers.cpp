#include <unordered_set>
#include <iterator>
#include <iostream>
#include <fstream>

using namespace std;

struct Point {
 int x, y;
};

struct Point_hash {
size_t operator()(const Point& p) const {
    size_t h = 0;
    hash<int> hx;
    hash<int> hy;
    h = hx(p.x) ^ hy(p.y);
    return h;
    }
};

struct Point_equal {
bool operator()(const Point& p1, const Point& p2) const {
    return (p1.x==p2.x) && (p2.y==p2.y);
    }
};

int main(void) {
 // define the hash set for storing the point
 unordered_set<Point,Point_hash,Point_equal> table;

 ifstream in("point_list.txt");
 cout << "Reading points from file" << endl;
 while (!in.eof()) {
    int x, y;
    in >> x >> y;

    Point p{x,y};
    table.insert(p);
 }
 cout << "Points read from file. Now enter some query point." << endl;

 while (cin) {
    int x, y;
    cin >> x >> y;
    Point p{x,y};

    // check if p is in the table, 
    // if it is print "point found"
    // otherwise print "not found"
    auto it = table.find(p);
    if(it == table.end()) cout << "not found" << endl;
    else cout << "point found" << endl;
 }
}