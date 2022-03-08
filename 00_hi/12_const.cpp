#include <iostream>

using namespace std;

/*
    cpp中const修饰的局部变量无法改变 - 符号表?

    const修饰全局变量（存放在常量区），无论是在c或c++中都无法改变
*/
int main() {
    const int size = 2;
    int arr[size] = {6, 8}; 
    cout << arr[0] << endl;
    return 0;
}
