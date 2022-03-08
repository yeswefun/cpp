#include <iostream>
#include "03_str.h"

using namespace std;

void test00() {
    String s("hello");
    cout << s << endl;
}

void test01() {
    int a = 10;
    int b = 20;
    cout << a << endl;
    cout << b << endl;
    cout << "int int" << endl;
    cin >> a >> b;
    cout << a << endl;
    cout << b << endl;
}

void test02() {
    String s("hello");
    cout << s << endl;
    cin >> s;
    cout << s << endl;
}

void test03() {
    String s("hello");
    String s2(s);
    String s3 = "";
    String s4 = "";

    s4 = s3 = s2;
    s3 = "";
}

void test04() {
    String s("hello");
    cout << s[0] << s[3] << endl;
    s[0] = 'H';
    s[3] = 'L';
    cout << s[0] << s[3] << endl;
}

void test05() {
    String s1("hello");
    String s2("world");
    String s4;
    s4 = s1 + s2;
    cout << s4 << endl;
    String s5;
    s5 = s2 + "world";
    cout << s5 << endl;
}

void test06() {
    String s1("hello");
    String s2("hello");
    String s3("world");
    cout << (s1 == s2) << endl;
    cout << (s1 == "hello") << endl;
    cout << (s3 == s2) << endl;
    cout << (s3 == "hello") << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << (s1 != s2) << endl;
    cout << (s1 != "hello") << endl;
    cout << (s3 != s2) << endl;
    cout << (s3 != "hello") << endl;

}

int main() {
    
    test00();
    cout << "***************************************" << endl;
    
    test01();
    cout << "***************************************" << endl;

    test02();
    cout << "***************************************" << endl;

    test03();
    cout << "***************************************" << endl;

    test04();
    cout << "***************************************" << endl;

    test05();
    cout << "***************************************" << endl;

    test06();
    cout << "***************************************" << endl;

    return 0;
}
