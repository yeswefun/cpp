#include <iostream>

using namespace std;

class MyStr {
public:
    MyStr(const char *str) {
        cout << "char*" << endl;
    }
    explicit MyStr(int size) {
        cout << "int" << endl;
    }
    int m_size;
    char *m_str;
};

// explicit forbide: MyStr str = 888;
int main() {
    // error: invalid conversion from ‘int’ to ‘const char*’
    //MyStr str = 888;
    MyStr str2 = MyStr(666);
    MyStr str3 = "abc";
    MyStr str4 = MyStr("abc");
    return 0;
}
