#include <iostream>

using namespace std;

class A {
public:
    int a;
protected:
    int b;
private:
    int c;
};

class B : public A {
};

class C : protected A {
};

class D : private A {
};

/*
继承深入
    都继承过来了呀，访问不了是因为编译器conceal了
    开发人员命令提示符
    cl /d1 reportSingleClassLayout类名 test.cpp，例子如下:
    $ cl /d1 reportSingleClassLayoutB test.cpp
*/
int main() {
    cout << sizeof(A) << endl;	// 12
    cout << sizeof(B) << endl;	// 12
    cout << sizeof(C) << endl;	// 12
    cout << sizeof(D) << endl;	// 12
    return 0;
}
