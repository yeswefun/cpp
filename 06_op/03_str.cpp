//string.cpp
#include "03_str.h"

ostream& operator<<(ostream &cout, const String &s) {
    if (s.p != NULL) {
        cout << s.p;
    }
    return cout;
}

istream& operator>>(istream &cin, String &s) {
    if (s.p != NULL) {
        delete [] s.p;
        s.p = NULL;
    }
    char buf[32];
    cin >> buf;
    s.size = strlen(buf);
    s.p = new char[s.size + 1];
    strncpy(s.p, buf, s.size);
    return cin;
}

String::String() {
    this->size = 0;
    this->p = NULL;
    cout << "no-arg" << endl;
}

String::String(const char *s) {
    cout << "String(const char *s)" << endl;
    this->size = strlen(s);
    this->p = new char[this->size + 1];
    strcpy(this->p, s);
}

String::String(const String &s) {
    cout << "String(const String &s)" << endl;
    this->size = strlen(s.p);
    this->p = new char[this->size + 1];
    strcpy(this->p, s.p);
}

String::~String() {
    cout << "~String" << endl;
    if (this->p != NULL) {
        delete [] this->p;
        this->p = NULL;
    }
}

String& String::operator=(const char *s) {
    cout << "String& String::operator=(const char *s)" << endl;
    if (this->p != NULL) {
        delete [] this->p;
        this->p = NULL;
    }
    this->size = strlen(s);
    this->p = new char[this->size+1];
    strcpy(this->p, s);
    return *this;
}

String& String::operator=(const String &s) {
    cout << "String& String::operator=(const String &s)" << endl;
    if (this->p != NULL) {
        delete [] this->p;
        this->p = NULL;
    }
    this->size = strlen(s.p);
    this->p = new char[this->size + 1];
    strcpy(this->p, s.p);
    return *this;
}

char& String::operator[](int index) {
    return this->p[index];
}

String String::operator+(const char *s) {
    String o;
    o.size = this->size + strlen(s);
    o.p = new char[o.size + 1];
    strcat(o.p, this->p); // o.p += this->p
    strcat(o.p, s); // o.p += s
    return o;
}

/*
String String::operator+(const String &s) {
    String o;
    o.size = this->size + strlen(s.p);
    o.p = new char[o.size + 1];    
    strcat(o.p, this->p);
    strcat(o.p, s.p);
    return o;
}
*/
String String::operator+(const String &s) {
    int size = this->size + strlen(s.p);
    char *tmp = new char[size + 1];
    memset(tmp, 0, size+1);
    strcpy(tmp, this->p);
    // strcpy(tmp, s.p); // err
    strcpy(tmp+this->size, s.p);
    String o(tmp);
    o.size = size;
    delete [] tmp;
    return o;
}

bool String::operator==(const char *s) {
    return this->size == strlen(s) && strcmp(this->p, s) == 0;
}

bool String::operator==(const String &s) {
    return this->size == strlen(s.p) && strcmp(this->p, s.p) == 0;
}

bool String::operator!=(const char *s) {
    return !this->operator==(s);
}

bool String::operator!=(const String &s) {
    return !this->operator==(s);
}