#include <iostream>
using namespace std;

// static int a = 100;
// static int b = 200;
namespace {
    int a = 100;
    int b = 200;
}

/*
    可以存在匿名命名空间
*/
int main() {
    cout << a << endl;
    cout << b << endl;
    return 0;
}
