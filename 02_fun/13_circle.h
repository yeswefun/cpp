// circle.h
#pragma once
#include "13_point.h"

#include <iostream>
#include <cmath>


class Circle {
public:
    void setR(int r);
    int getR();
    void setPoint(Point p);
    Point getPoint();
    // -1 - in，0 - on，1 - out
    int where(Point p);
private:
    int m_r;
    Point m_p;
};
