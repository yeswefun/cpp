#include <iostream>
#include <string>

using namespace std;

void testx(string s) {
    cout << '[' << s << ']' << endl;
}

void testy(const char *s) {
    cout << '[' << s << ']' << endl;
}

/*
    string和c-style字符串转换
*/
int main() {
    string s = "666";

    // string -> const char* -> const_cast -> char*
    const char *p = s.c_str();
    cout << p << endl;

    // const char* -> string
    string s2(p);
    cout << s2 << endl;

    // const char* -> string, string(const char*)
    testx(p);

    // string X-> const char*, 不能直接转换
    //testy(s);
    testy(s.c_str());

    return 0;
}
