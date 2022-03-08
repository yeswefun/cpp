#include <iostream>

using namespace std;

class A {
public:
    A(int id, string name) : id(id), name(name) {}
    int id;
    string name;
};


/*
    对组(pair)将一对值组合成一个值，这一对值可以具有不同的数据类型，
    两个值可以分别用pair的两个公有属性first和second访问
*/
int main() {
    // int -> p.first
    // string -> p.second
    pair<int, string> p(6, "Java");
    cout << p.first << endl;
    cout << p.second << endl;
    cout << "*********************************" << endl;

    // int -> p.first
    // string -> p.second
    pair<int, string> p2 = make_pair(8, "C++");
    cout << p2.first << endl;
    cout << p2.second << endl;
    cout << "*********************************" << endl;

    A a(6, "C++");
    A b(8, "C");
    // A -> p.first
    // A* -> p.second
    pair<A, A*> p3(a, &b);
    cout << p3.first.id << '@' << p3.first.name << endl;
    cout << p3.second->id << '@' << p3.second->name << endl;
    cout << "*********************************" << endl;

    A a2(9, "Java");
    A b2(7, "go");
    // A -> p.first
    // A* -> p.second
    pair<A, A*> p4 = make_pair(a2, &b2);
    cout << p4.first.id << '@' << p4.first.name << endl;
    cout << p4.second->id << '@' << p4.second->name << endl;

    return 0;
}
