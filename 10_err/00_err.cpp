#include <iostream>

using namespace std;

int myDivide(int x, int y) {
    if (y == 0) {
        return -1;
    }
    return x / y;
}

int main() {

    int a = 10;
    int b = 10;
    int c = -10;
    int d = 0;

    cout << myDivide(a, b) << endl; // 1
    
    // -1 到底是正常结果，还是出现异常
    cout << myDivide(a, c) << endl; // -1
    cout << myDivide(a, d) << endl; // -1

    return 0;
}