#include <iostream>

using namespace std;

void swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
    cout << a << "@" << b << endl;
}

void swap2(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    cout << *a << "@" << *b << endl;
}

/*
    int* const p == int &a;
    *p == a
     p == &a
    sizeof(*p) == sizeof(a)
*/
void swap3(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    cout << "swap3: " << a << "@" << b << endl;
    cout << "swap3: " << &a << "@" << &b << endl;
    cout << "swap3: " << sizeof(a) << "@" << sizeof(b) << endl;
}

int main() {
    int a = 10;
    int b = 20;
    cout << a << "@" << b << endl;
    cout << &a << "@" << &b << endl;
    cout << sizeof(a) << "@" << sizeof(b) << endl;
    //swap(a, b);
    //swap2(&a, &b);
    swap3(a, b);
    cout << a << "@" << b << endl;
    cout << &a << "@" << &b << endl;  
    return 0;
}
