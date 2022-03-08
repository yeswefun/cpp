#include <iostream>

using namespace std;

class A {
public:
    int a = 1;
protected:
    int b = 2;
private:
    int c = 3;
};

class B: public A {
public:
    B() {
        cout << a << endl;
        cout << b << endl;
        // error: ‘int A::c’ is private within this context
        //cout << c << endl;
    }
};

class C: protected A {
public:
    C() {
        cout << a << endl;
        cout << b << endl;
        //  error: ‘int A::c’ is private within this context
        //cout << c << endl;
    }
};

class D: private A {
public:
    D() {
        cout << a << endl;
        cout << b << endl;
        //  error: ‘int A::c’ is private within this context
        //cout << c << endl;
    }
};

void test_public() {
    B b;
    cout << b.a << endl;

    // error: ‘int A::b’ is protected within this context
    //cout << b.b << endl;

    // error: ‘int A::c’ is private within this context 
    //cout << b.c << endl;
}

void test_protected() {
    C c;
    // error: ‘int A::a’ is inaccessible within this context
    //cout << c.a << endl;

    // error: ‘int A::b’ is protected within this context
    //cout << c.b << endl;

    // error: ‘int A::c’ is private within this context 
    //cout << c.c << endl;
}
void test_private() {
    D d;
    // error: ‘int A::a’ is inaccessible within this context
    //cout << d.a << endl;

    // error: ‘int A::b’ is protected within this context
    //cout << d.b << endl;

    // error: ‘int A::c’ is private within this context 
    //cout << d.c << endl;
}

/*
    public(宽松) > protected(严格) > private(更严格)
    子类成员的访问权限都是在父类中访问权限与继承访问权限二者中比较严格的访问权限
*/
int main() {
    test_public();
    test_protected();
    test_private();
    return 0;
}
