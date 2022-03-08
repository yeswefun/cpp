#include <iostream>
using namespace std;

namespace A {
    int a = 10;
    int b = 20;
}

// using声明
void test00() {
    int a = 20;
    cout << a << endl;	// 20
    //与前面的a冲突了
    //using A::a;
    cout << a << endl;	// 20
    cout << "***************" << endl;
}

// using编译指令
void test01() {
    int a = 30;
    using namespace A;
    cout << a << endl;	// 30
    cout << b << endl;	// 20
    cout << "***************" << endl;
}

namespace B {
    int a = 20;
}

void test02() {
    int a = 30;
    using namespace A;
    using namespace B;
    cout << A::a << endl;// 10
    cout << B::a << endl;// 20
    cout << a << endl;	 // 30
}

int main() {
    test00();
    test01();
    test02();
    return 0;
}
