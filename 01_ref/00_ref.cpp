#include <iostream>

using namespace std;

/*
    引用基本使用
*/
int main() {

    int a = 10;
    int &b = a;

    cout << &a << "@" << a << endl;
    cout << &b << "@" << b << endl;

    b = 30;

    cout << &a << "@" << a << endl;
    cout << &b << "@" << b << endl;

    return 0;
}
