// point.h
#pragma once
  
class Point {
public:
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
private:
    int m_x;
    int m_y;
};
