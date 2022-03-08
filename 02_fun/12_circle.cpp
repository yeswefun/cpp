#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    void setX(int x) {
        m_x = x;
    }
    void setY(int y) {
        m_y = y;
    }
    int getX() {
        return m_x;
    }
    int getY() {
        return m_y;
    }
private:
    int m_x;
    int m_y;
};

class Circle {
public:
    void setR(int r) {
        m_r = r;
    }
    int getR() {
        return m_r;
    }
    void setPoint(Point p) {
        m_p = p;
    }
    Point getPoint() {
        return m_p;
    }
    // -1 - in，0 - on，1 - out
    int where(Point p) {
        int d1 = pow(m_p.getX() - p.getX(), 2)
            	+ pow(m_p.getY() - p.getY(), 2);
        int d2 = pow(m_r, 2);
        cout << d1 << " # " << d2 << endl;
        if (d1 > d2) {
            return 1;
        } else if (d1 < d2) {
            return -1;
        } else {
            return 0;
		}
    }
private:
    int m_r;
    Point m_p;
};

/*
    点到圆心的距离与半径的大小关系
*/
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
