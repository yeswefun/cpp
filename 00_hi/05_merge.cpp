#include <iostream>
using namespace std;

namespace A {
    int a = 100;
}

namespace A {
    int b = 200;
}

/*
    同文件中同名命名空间可以合并
*/
int main() {
    cout << A::a << endl;
    cout << A::b << endl;
    return 0;
}
