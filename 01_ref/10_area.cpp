#include <iostream>

using namespace std;

const double PI = 3.14;

class Circle {
public:
    void setRadius(int r) {
        m_r = r;
    }
    // c = 2 * PI * r
    double circumference() {
        return 2 * PI * m_r;
    }
    // s = PI * r * r
    double area() {
        return PI * m_r * m_r;
    }
public:
    // the radius of circle
    int m_r;
};

/*
    求圆的面积
*/
int main() {
    Circle c1;
    //c1.radius = 10;
    c1.setRadius(10);
    cout << c1.circumference() << endl;
    cout << c1.area() << endl;
    return 0;
}
