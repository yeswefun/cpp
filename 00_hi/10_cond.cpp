#include <iostream>

using namespace std;

/*
    三目运算符增强
*/
int main() {
    int a = 10;
    int b = 20;
    // c语言返回的是值，c++返回的是变量
    // c语言 *(a > b ? &a : &b) = 666; // error
    a > b ? a : b = 666;
    cout << b << endl;
    return 0;
}
