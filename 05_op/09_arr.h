// myarr.h
#pragma once

#include <iostream>
using namespace std;

class Arr {
public:
    Arr();
    Arr(int cap);
    Arr(const Arr &arr);
    ~Arr();
    void push(int val);
    int get(int index);
    void set(int index, int val);
    int getLen();
    int getCap();
    int& operator[](int index);
private:
    int *p;
    int len;
    int cap;
};
