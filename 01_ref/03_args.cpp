#include <iostream>

using namespace std;

void swap4(int *a, int *b) {
    int *tmp = a;
    a = b;
    b = tmp;
    cout << *a << '-' << *b << endl;
}

void swap5(int* &a, int* &b) {
    int *tmp = a;
    a = b;
    b = tmp;
    cout << *a << '-' << *b << endl;
}

/*
    指针引用
*/
int main() {
    
    int a = 10;
    int b = 20;

    int *pa = &a;
    int *pb = &b;

    cout << "main: " << *pa << '-' << *pb << endl;

    swap4(pa, pb);

    cout << "main: " << *pa << '-' << *pb << endl;

    swap5(pa, pb);

    cout << "main: " << *pa << '-' << *pb << endl;

    return 0;
}
