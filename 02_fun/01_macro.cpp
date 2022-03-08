#include <iostream>

using namespace std;

#define CMP(x, y) (((x) > (y)) ? (x) : (y))

int cmp(int x, int y) {
    return x > y ? x : y;
}

int main() {

    int a = 30;
    int b = 20;
    // ++a > b ? ++a : b
    int rst = CMP(++a, b);  // 32
    cout << rst << endl;

    int x = 30;
    int y = 20;
    int rst2 = cmp(++x, y); // 31
    cout << rst2 << endl;

    return 0;
}
