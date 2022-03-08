#include <iostream>

using namespace std;

#define ADD(x, y) ((x)+(y))
#define ADD2(x, y) x+y

int main() {

    // ((1) + (2)) * 3 = 9
    int rst = ADD(1, 2) * 3;
    cout << rst << endl; // 9
    
    // 1 + 2 * 3 = 7
    int rst2 = ADD2(1, 2) * 3;
    cout << rst2 << endl; // 7

    return 0;
}
