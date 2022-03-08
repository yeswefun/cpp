// circle.cpp
#include "13_circle.h"

using namespace std;

void Circle::setR(int r) {
    m_r = r;
}
int Circle::getR() {
    return m_r;
}
void Circle::setPoint(Point p) {
    m_p = p;
}
Point Circle::getPoint() {
    return m_p;
}
int Circle::where(Point p) {
    int d1 = pow(m_p.getX() - p.getX(), 2) + pow(m_p.getY() - p.getY(), 2);
    int d2 = pow(m_r, 2);
    cout << d1 <<  " # "  << d2 << endl;
    if (d1 > d2) {
        return 1;
    } else if (d1 < d2) {
        return -1;
    } else {
        return 0;
    }
}
