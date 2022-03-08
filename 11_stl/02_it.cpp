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

void fnPrint(A *a) {
    cout << a->id << "@" << a->name << endl;
}

/*
    自定义类型指针
*/
int main() {
    vector<A*> v;
    A a1(1, "C");
    A a2(2, "go");
    A a3(3, "C++");
    A a4(4, "Java");
    
    //error: taking address of temporary
    // v.push_back(&A{1, "xxx"});
    v.push_back(&a1);
    v.push_back(&a2);
    v.push_back(&a3);
    v.push_back(&a4);
    
    for_each(v.begin(), v.end(), fnPrint);
    cout << "************************" << endl;
    
    for (vector<A*>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << (*it)->id << "@" << (*it)->name << endl;
    }
    cout << "************************" << endl;

    vector<A*>::iterator begin = v.begin();
    vector<A*>::iterator end = v.end();
    while (begin != end) {
        cout << (*begin)->id << "@" << (*begin)->name << endl;
        ++begin;
    }
    
    return 0;
}
