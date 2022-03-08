// myarr.cpp
#include "09_arr.h"
  
Arr::Arr() {
    cout << "construct - no-arg" << endl;
    this->len = 0;
    this->cap = 16;
    this->p = new int[16];
}

Arr::Arr(int cap) {
    cout << "construct - cap: " << cap << endl;
    this->len = 0;
    this->cap = cap;
    this->p = new int[cap];
}

Arr::Arr(const Arr &arr) {
    cout << "construct - copy" << endl;
    this->len = arr.len;
    this->cap = arr.cap;
    this->p = new int[arr.cap];
    for (int x = 0; x < arr.len; x++) {
        this->p[x] = arr.p[x];
    }
}

Arr::~Arr() {
    if (this->p != NULL) {
        cout << "destruct" << endl;
        delete [] this->p;
        this->p = NULL;
    }
}

void Arr::push(int val) {
    this->p[this->len++] = val;
}

int Arr::get(int index) {
    return this->p[index];
}

void Arr::set(int index, int val) {
    this->p[index] = val;
}

int Arr::getLen() {
    return this->len;
}

int Arr::getCap() {
    return this->cap;
}

/*
    小括号：Parentheses, bracket
    中括号：bracket
    大括号：brace
*/
int& Arr::operator[](int index) {
    return this->p[index];
}
