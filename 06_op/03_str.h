//string.h
#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class String {

friend ostream& operator<<(ostream &cout, const String &s); // 读操作
friend istream& operator>>(istream &cin, String &s); // 写操作

public:
    String();
    String(const char *s);
    String(const String &s);
    ~String();
    String& operator=(const char *s);
    String& operator=(const String &s);
    char& operator[](int index);
    String operator+(const char *s);
    String operator+(const String &s);
    bool operator==(const char *s);
    bool operator==(const String &s);
    bool operator!=(const char *s);
    bool operator!=(const String &s);
private:
    char *p;
    int size;
};
