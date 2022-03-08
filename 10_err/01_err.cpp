#include <iostream>

using namespace std;

int myDivide(int x, int y) {
    if (y == 0) {
        // 抛出异常
        throw -1;
    }
    return x / y;
}

int main() {

    int a = 10;
    int b = 10;
    int c = -10;
    int d = 0;

    // -1 到底是正常结果，还是出现异常
    // cout << myDivide(a, c) << endl; // -1
    // cout << myDivide(a, d) << endl; // -1

    try {
        cout << myDivide(a, d) << endl;
    } catch (int) { // 异常抛出的类型
        cout << "catch int error" << endl;
    }

    return 0;
}