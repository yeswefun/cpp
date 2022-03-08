#include <iostream>
#include "13_point.h"
#include "13_circle.h"

using namespace std;

// g++ 02_pc.cpp point.cpp circle.cpp -o x && ./x
int main() {
    Point p;
    p.setX(0);
    p.setY(0);

    Circle c;
    c.setR(10);
    c.setPoint(p);

    Point p2;
    p2.setX(0);
    p2.setY(0);
    cout << c.where(p2) << endl;

    p2.setX(10);
    cout << c.where(p2) << endl;

    p2.setX(20);
    cout << c.where(p2) << endl;
    return 0;
}
