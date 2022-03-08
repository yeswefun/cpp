#include <iostream>
#include <vector>   // vector
#include <algorithm>// for_each

using namespace std;

class A {
public:
    A(int id, string name) : id(id), name(name) {}
    int id;
    string name;
};

void fnPrint(A &a) {
    cout << a.id << "@" << a.name << endl;
}

/*
    自定义类型
*/
int main() {
    vector<A> v;
    v.push_back(A(1, "C"));
    v.push_back(A(2, "go"));
    v.push_back(A(3, "C++"));
    v.push_back(A(4, "Java"));
    
    for_each(v.begin(), v.end(), fnPrint);
    cout << "************************" << endl;
    
    for (vector<A>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << it->id << "@" << (*it).name << endl;
    }
    cout << "************************" << endl;

    vector<A>::iterator begin = v.begin();
    vector<A>::iterator end = v.end();
    while (begin != end) {
        cout << begin->id << "@" << begin->name << endl;
        ++begin;
    }

    return 0;
}
