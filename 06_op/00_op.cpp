#include <iostream>

using namespace std;

class User {
public:
    User(int id, string name) :id(id), name(name) {}
    bool operator==(const User &u) {
        return this->id == u.id && this->name == u.name;
    }
    bool operator!=(const User &u) {
        return !(this->id == u.id && this->name == u.name);
    }
public:
    int id;
    string name;
};

/*
    关系运算符重载
        ==, !=
*/
int main() {
    User u1(10, "C");
    User u2(20, "C++");
    User u3(10, "C");

    if (u1 == u3) {
        cout << "==" << endl;
    } else {
        cout << "!=" << endl;
    }

    if (u1 != u2) {
        cout << "!=" << endl;
    } else {
        cout << "==" << endl;
    }

    return 0;
}
